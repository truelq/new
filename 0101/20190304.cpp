#include <bits/stdc++.h>

using namespace std;
struct ins {
  int io;
  int id;
};

struct threads {
  int id;
  int current;
  vector<ins> save;
};

int t, n;
int stat[1001];
int st[1001][1001];
vector<threads> ss;
threads temp;
int main() {
  int id;
  int state;
  string tt;
  scanf("%d%d", &t, &n);
  getchar();
  for (int i = 0; i < t; ++i) {
    ss.clear();
    for (int j = 0; j < n; ++j) {
      temp.id = i;
      temp.current = 0;
      temp.save.clear();
      getline(cin, tt);
      for (int k = 0; k < tt.size(); ++k) {
        if (tt[k] == 'S')
          state = tt[k];
        else if (tt[k] == 'R')
          state = tt[k];
        else if (tt[k] >= '0' && tt[k] <= '9') {
          id = tt[k] - '0';
          int l;
          for (l = k + 1; l < tt.size() && tt[l] >= '0' && tt[l] <= '9'; ++l)
            id = id * 10 + tt[l] - '0';
          k = l;
          temp.save.push_back({state, id});
        }
      }
      /*do {
        scanf("%c%d", &state, &id);
        temp.save.push_back({state, id});
      } while (getchar() != '\n');
      */
      ss.push_back(temp);
    }
    for (int i = 0; i < 1000; ++i)
      stat[i] = -1;
    while (true) {
      int flag, fla;
      flag = fla = 0;
      for (int j = 0; j < n; ++j) {
        if (ss[j].current < ss[j].save.size()) {
          flag = 1;
          if (ss[j].save[ss[j].current].io == 'S') {
            if (stat[j] == -1) {
              stat[j] = ss[j].save[ss[j].current].id;
              //ss[j].current++;
              fla = 1;
            }
          } else {
            int temp = ss[j].save[ss[j].current].id;
            if (stat[temp] == j) {
              ss[j].current++;
              ss[temp].current++;
              stat[temp] = -1;
              fla = 1;
            }
          }
        }
      }
      if (!flag) {
        printf("0\n");
        break;
      }
      if (!fla) {
        printf("1\n");
        break;
      }
    }
  }
}