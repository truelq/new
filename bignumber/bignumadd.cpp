#include <iostream>
#include<string>
#include<math.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    for (int i = 0; i < a;++i){
        
        string m, n;
        cin >> m >> n;
        cout << "Case " << i + 1 << ':' << endl;
        cout << m << " + " << n << " = ";
        int more = 0;
        int mlength = m.length();
        int nlength = n.length();
        int max = (mlength > nlength ? mlength : nlength) +1;
        char *p = new char[max+1];
        p[max] = 0;
        while(mlength&&nlength){
            int temp = m[mlength - 1] + n[nlength - 1] - '0' - '0'+more;
            more = temp / 10;
            p[max - 1] = temp % 10+'0';
            --max;
            --mlength;
            --nlength;
        }
        while(mlength){
            int temp = m[mlength - 1] + more - '0';
            more = temp / 10;
            p[max - 1] = temp % 10+'0';
            --max;
            --mlength;
        }
        while(nlength){
            int temp = n[nlength - 1] + more - '0';
            more = temp / 10;
            p[max - 1] = temp % 10+'0';
            --max;
            --nlength;
        }
        
        if(more){
            p[0] = more + '0';
            cout << p << endl;
        }else
            cout << p + 1 << endl;
        delete p;
        if(i<a-1)
            cout << endl;
    }
    return 0;
}