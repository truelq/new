#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s1[] = "\x46\x16\x45\x4c\x5b\x16\x47\x10\x1b\x00\x52\x13\x1f\x2\x5c";
    char s2[] = "1a2b3c4d5e6f";
    for (int i = 0; i < 15;++i){
        printf("%c", s1[i] ^ s2[i%12]);
    }

        getchar();
    getchar();
    return 0;
}