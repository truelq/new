//监视HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run项
 
#include <windows.h>
 
//定义一个监视注册表启动项的函数
int reg()
{
   HANDLE hNotify;
   HKEY hKeyx;
   //DWORD dwRes;
 
   hNotify = CreateEventA(NULL, //不使用SECURITY_ATTRIBUTES结构
         FALSE, //不自动重置
         TRUE,   //设置初始状态
         "RegistryNotify" //事件对象的名称
         );
 
   if (hNotify == 0)
   {
     MessageBoxA(NULL,"CreateEvent failed"," ",MB_OK);
     ExitProcess(0);
   }
 
   if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, //根键
         "Software\\Microsoft\\Windows\\CurrentVersion\\Run", //子键
         0, //reserved
         KEY_NOTIFY, //监视用
         &hKeyx //保存句柄
         ) != ERROR_SUCCESS)
   {
     CloseHandle(hNotify);
     MessageBoxA(NULL,"RegOpenKeyEx failed"," ",MB_OK);
     ExitProcess(0);
   }
 
   if (RegNotifyChangeKeyValue(hKeyx, //监视子键句柄
         TRUE, //监视此项的子键
         REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_LAST_SET, //监视增加或删除了子键，监视键值发生是否改变
         hNotify, //接受注册表变化事件的事件对象句柄
         TRUE //注册表变化前报告
         ) != ERROR_SUCCESS)
   {
     CloseHandle(hNotify);
     RegCloseKey(hKeyx);
     MessageBoxA(NULL,"RegNotifyChangeKeyValue failed"," ", MB_OK);
     ExitProcess(0);
   }
 
   if (WaitForSingleObject(hNotify, INFINITE) != WAIT_FAILED)
   {
     MessageBoxA(NULL,"注册表有改动"," ",MB_OK);
   }
 
   CloseHandle(hNotify);
   RegCloseKey(hKeyx);
 
   return 0;
 
}
 
void main()
{
	reg();
}