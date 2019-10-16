#include <iostream>
#include <stdio.h>

#include <string.h>
using namespace std;
char ss[2][5001];
int main()
{
    int i, j;
    i = j = 0;
    for (i = 0; (ss[0][i] = getchar()) != '.'; ++i)
        ;
    for (j = 0; (ss[1][j] = getchar()) != '.'; ++j)
        ;
    
}