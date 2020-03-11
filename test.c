#include<stdio.h>

int main(){
    FILE *file=fopen("test.txt","wb");
    char a=15*16;
    for(int i=0;i<100;++i){
        fwrite(&a,1,1,file);
    }
    fclose(file);
}