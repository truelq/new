#include <stdio.h>
#define CHANGE 1
int main() {
  char s[100];
  int i = 0;
  gets(s);
#if CHANGE
  while (s[i] != '\0') {
    if (s[i] <= 'z' && s[i] >= 'a')
      s[i] = s[i] - 'a' + 'A';
    else if (s[i] <= 'Z' && s[i] >= 'A')
      ;
    s[i] = s[i] + ('a' - 'A');
    i++;
  }
#endif
  puts(s);
  return 0;
}
