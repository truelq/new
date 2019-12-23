#include<stdio.h>
struct bits{
	unsigned short bit0:1,bit1:1,bit2:1,bit3:1,bit4:1,bit5:1,bit6:1,bit7:1;
};
union w8{
	short k;
	struct bits byte;
};
void f0(struct bits b);
void f1(struct bits b);
void f2(struct bits b);
void f3(struct bits b);
void f4(struct bits b);
void f5(struct bits b);
void f6(struct bits b);
void f7(struct bits b);
int main()
{
	short n;
	scanf("%hd",&n);
	union w8 w={n};
	int i;
	void (*p_fun[8])(struct bits );
	p_fun[0]=f0;
	p_fun[1]=f1;
	p_fun[2]=f2;
	p_fun[3]=f3;
	p_fun[4]=f4;
	p_fun[5]=f5;
	p_fun[6]=f6;
	p_fun[7]=f7;
	p_fun[0](w.byte);
	p_fun[1](w.byte);
	p_fun[2](w.byte);
	p_fun[3](w.byte);
	p_fun[4](w.byte);
	p_fun[5](w.byte);
	p_fun[6](w.byte);
	p_fun[7](w.byte);
	return 0;
} 
void f0(struct bits b)
{
	if(b.bit0)
		printf("the 1 function %d is called!\n",b.bit0);
} 
void f1(struct bits b)
{ 
	if(b.bit1)
	printf("the 2 function %d is called!\n",b.bit1);
} 
void f2(struct bits b)
{
	if(b.bit2)
	printf("the 3 function %d is called!\n",b.bit2);
} 
void f3(struct bits b)
{
	if(b.bit3)
	printf("the 4 function %d is called!\n",b.bit3);
} 
void f4(struct bits b)
{
	if(b.bit4)
	printf("the 5 function %d is called!\n",b.bit4);
} 
void f5(struct bits b)
{
	if(b.bit5)
	printf("the 6 function %d is called!\n",b.bit5);
} 
void f6(struct bits b)
{
	if(b.bit6)
	printf("the 7 function %d is called!\n",b.bit6);
} 
void f7(struct bits b)
{
	if(b.bit7)
	printf("the 8 function %d is called!\n",b.bit7);
} 

