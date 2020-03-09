#include <bits/stdc++.h>
#include <string>

using namespace std;
struct ss {
  string src;
  string name;
  int state = 0;
  int eee = 0;
  vector<string> list;
};
ss sss[101];
ss ssm[101];
vector<string> ans;

void profi(ss &t) {
  string temp = t.src;
  if (temp[temp.size() - 1] == '/')
    t.eee = 1;
  while (!temp.empty()) {
    int pos = temp.find('/');
    if (pos == temp.npos) {
      t.list.push_back(temp);
      // cout << t.list[t.list.size() - 1] << endl;
      if (t.list[t.list.size() - 1] == "<path>") {
        t.state = 1;
      }
      break;
    }
    t.list.push_back(temp.substr(0, pos));
    if (t.list[t.list.size() - 1] == "<path>") {
      t.state = 1;
    }
    temp.erase(temp.begin(), temp.begin() + pos + 1);

    // cout << t.list[t.list.size() - 1] << endl;
  }
}
int match(ss &src, ss &des) {
  if ((src.list.size() == des.list.size() ||
       src.state == 1 && src.eee == des.eee)) {
    for (int i = 0; i < src.list.size(); ++i) {
      if (src.list[i] == "<int>") {
        string temp = des.list[i];
        int t = 0;
        for (int j = 0; j < temp.size(); ++j) {
          if (temp[j] <= '9' && temp[j] >= '0') {
            t = t * 10 + temp[j] - '0';
          } else {
            return 0;
          }
        }
        ans.push_back(to_string(t));
      } else if (src.list[i] == "<str>") {
        ans.push_back(des.list[i]);
      } else if (src.list[i] == "<path>") {
        string st;
        for (int j = i; j < des.list.size(); ++j) {
          st += des.list[j];
          st += "/";
        }
        if (st.empty()) {
          return 0;
        }
        //if (src.eee == des.eee)
          st.erase(st.end() - 1, st.end());
        ans.push_back(st);
        return 1;
      } else {
        if (src.list[i] != des.list[i]) {
          return 0;
        }
      }
    }
    return 1;
  }
  return 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  string temp;
  for (int i = 0; i < n; ++i) {
    cin >> sss[i].src;
    cin >> sss[i].name;
    profi(sss[i]);
  }
  for (int i = 0; i < m; ++i) {
    cin >> ssm[i].src;
    profi(ssm[i]);
    int flag = 0;
    for (int j = 0; j < n; ++j) {
      ans.clear();
      if (match(sss[j], ssm[i])) {
        cout << sss[j].name;
        for (int k = 0; k < ans.size(); ++k) {
          cout << ' ' << ans[k];
        }
        cout << endl;
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << "404" << endl;
    }
  }

  return 0;
}