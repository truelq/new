#include<iostream>
using std::cout;
using std::cin;
using std::endl;
struct Windows{
        int xl,yl,xr,yr;
        int postion;
    };
int main()
{
    int m,n;
    struct Windows points[10];
    int eeeee[10];
    int aaaaa[10];

    cin>>m>>n;
    for(int i=0;i<m;++i){
        cin>>points[i].xl>>points[i].yl>>points[i].xr>>points[i].yr;
        points[i].postion=i+1;
    }
    for(int i=0;i<n;++i)
    {
        cin>>eeeee[i]>>aaaaa[i];
    }
    for(int i=0;i<n;++i)
    {
        int flag=0;
        
        for(int j=m-1;j>=0;--j)
        {
            if(eeeee[i]<=points[j].xr&&eeeee[i]>=points[j].xl&&aaaaa[i]<=points[j].yr&&aaaaa[i]>=points[j].yl){
                cout<<points[j].postion<<endl;
                struct Windows temp;
                temp.xl=points[j].xl;
                temp.xr=points[j].xr;
                temp.yr=points[j].yr;
                temp.yl=points[j].yl;
                temp.postion=points[j].postion;
                for(int k=j;k<m-1;++k)
                {
                    points[k].xl=points[k+1].xl;
                    points[k].xr=points[k+1].xr;
                    points[k].yr=points[k+1].yr;
                    points[k].yl=points[k+1].yl;
                    points[k].postion=points[k+1].postion;
                }
                points[m-1].xl=temp.xl;
                points[m-1].xr=temp.xr;
                points[m-1].yr=temp.yr;
                points[m-1].yl=temp.yl;
                points[m-1].postion=temp.postion;
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"IGNORED"<<endl;
    }
    getchar();
    getchar();

    return 0;
}
