#include<stdio.h>

int main(){
    FILE *file=fopen("test.txt","wb");
    char a=170;
    for(int i=0;i<1024*10;++i){
        fwrite(&a,1,1,file);
    }
    fclose(file);
}