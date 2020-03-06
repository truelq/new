#include<stdio.h>

int main(){
	int a=33;
	long long t=1;
	printf("1<<a 0<<32\n");
	printf("%lld %d\n",t<<a,0<<32);
	return 0;
}