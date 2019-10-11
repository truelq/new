#include <stdio.h>

#include<string.h>

int main(){
    char enflag[19];
    enflag[0] = '~';
    enflag[1] = 't';
    enflag[2] = 'u';
    enflag[3] = 0x7f;
    enflag[4] = 0x67;
    enflag[5] = 0x63;
    enflag[6] = 0x24;
    enflag[7] = 0x63;
    enflag[8] = 0x60;
    enflag[9] = 0x65;
    enflag[10] = 0x74;
    enflag[11] = 0x6D;
    enflag[12] = 0x24;
    enflag[13] = 0x7d;
    enflag[14] = 0x43;
    enflag[15] = 0x25;
    enflag[16] = 0x7a;
    enflag[17] = 0x69;
    enflag[18] = 0;
    char flag[] = "flag{this_is_fack}";
    printf("%d %d %d\n", enflag[0], enflag[1], enflag[2]);
    for (int i = 0; i < 19;i+=3){
      printf("%d %d", i,(char)(18^(flag[i]+6))-enflag[i]);
      for (int j = 32; j < 127;++j){
        if((char)(18^(j+6))==enflag[i])
          printf("%c\n", j);
      }
      printf("%d %d", i + 1, (char)((flag[i + 1] - 6) ^ 18) - enflag[i + 1]);
      for (int j = 32; j < 127;++j){
        if((char)((j - 6) ^ 18)== enflag[i + 1])
          printf("%c\n", j);
      }
      printf("%d %d", i + 2, (char)(flag[i + 2] ^ 6 ^ 18) - enflag[i + 2]);
      for (int j = 32; j < 127;++j){
        if((char)(j ^ 6 ^ 18) ==enflag[i + 2])
          printf("%c\n", j);
      }
      
    }
      getchar();
    getchar();
}