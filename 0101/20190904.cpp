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
int allk;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    cin >> id >> score;
    for (int j = 0; j < m; ++j) {
      ss.insert({j, id, score});
      save[{j, id}] = score;
    }
  }
  cin >> opnum;
  while (opnum--) {
    cin >> choice;
    switch (choice) {
    case 1:
      cin >> type >> id >> score;
      ss.insert({type, id, score});
      save[{type, id}] = score;
      break;
    case 2: {
      cin >> type >> id;
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
      int ans = 0;
      cin >> allk;
      for (int i = 0; i < m; ++i) {
        cin >> k[i];
        ans += k[i];
      }
      vector<int> pri[55];
      set<goods>::iterator it = ss.begin();
      while (allk && ans && it != ss.end()) {
        if (k[it->type] && save[{it->type, it->commodity}] == it->score) {
          pri[it->type].push_back(it->commodity);
          k[it->type]--;
          allk--;
          ans--;
        }
        it++;
      }
      for (int i = 0; i < m; ++i) {
        if (pri[i].size()) {
          // sort(pri[i].begin(), pri[i].end());
          for (int j = 0; j < pri[i].size(); ++j) {
            if (j == pri[i].size() - 1)
              cout << pri[i][j];
            else
              cout << pri[i][j] << ' ';
          }
        } else {
          cout << -1;
        }
        cout << endl;
      }
      break;
    }
    }
  }
  return 0;
}