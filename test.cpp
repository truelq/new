#include <stdio.h>
int main() {
  double x, d;
  double ans;
  x=0;
  for(x=0;x<2;x+=1e-6){
    ans=(((3*x-4)*x-5)*x+13);
    if(ans<=0){
      printf("%lf:%lf\n",x,ans);
    }
  }
  return 0;
}
