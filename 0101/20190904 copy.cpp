#include <bits/stdc++.h>

using namespace std;
struct goods {
  int type;
  int commodity;
  int score;
  bool operator<(const goods &b) const {
    if (score == b.score)
      if (type == b.type)
        return commodity < b.commodity;
      else
        return type < b.type;
    return score > b.score;
  }
};
struct good {
  int type;
  int commodity;
  bool operator<(const good &b) const {
    if (type == b.type)
      return commodity < b.commodity;
    return type < b.type;
  }
};

set<goods> ss;
map<good, int> save;
int n, m;
int opnum;
int type, id, score;
int choice;
int k[100];
vector<int> pri[100];
int allk;
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &id, &score);
    for (int j = 0; j < m; ++j)
      ss.insert({j, id, score});
  }
  scanf("%d", &opnum);
  while (opnum--) {
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      scanf("%d%d%d", &type, &id, &score);
      ss.insert({type, id, score});
      save[{type, id}] = score;
      break;
    case 2: {
      scanf("%d%d", &type, &id);
      save[{type, id}] = -1;
      /*
      set<goods>::iterator iter;
      for (iter = ss.begin(); iter != ss.end(); ++iter) {
        if (iter->type == type && iter->commodity == id) {
          ss.erase(iter);
          break;
        }
      }
      */
      break;
    }
    case 3: {
      scanf("%d", &allk);
      for (int i = 0; i < m; ++i)
        scanf("%d", k + i);
      for (int i = 0; i <= m; ++i)
        pri[i].clear();
      set<goods>::iterator it = ss.begin();
      while (allk && it != ss.end()) {
        if (k[it->type] && save[{it->type, it->commodity}] == it->score) {
          pri[it->type].push_back(it->commodity);
          k[it->type]--;
          allk--;
        }
        it++;
      }
      for (int i = 0; i < m; ++i) {
        if (pri[i].size()) {
          // sort(pri[i].begin(), pri[i].end());
          for (int j = 0; j < pri[i].size(); ++j) {
            if (j == pri[i].size() - 1)
              printf("%d", pri[i][j]);
            else
              printf("%d ", pri[i][j]);
          }
        } else {
          printf("-1");
        }
        printf("\n");
      }
      break;
    }
    }
  }
  return 0;
}