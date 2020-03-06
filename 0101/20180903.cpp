#include <algorithm>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
//元素选择器

using namespace std;
struct id {
  string id;
  string label;
  int depth = 0;
  void clear() {
    this->id.clear();
    this->label.clear();
    this->depth = 0;
  }
};
vector<id> ss;
string sss;

vector<string> st;
void cut() {
  st.clear();
  while (true) {
    int d = sss.find(' ');
    if (d == sss.npos) {
      st.push_back(sss);
      break;
    } else {
      st.push_back(sss.substr(0, d));
      sss.erase(0, d + 1);
    }
  }
}
int main() {
  int m, n;
  id temp;
  char tt[2048];
  cin >> n >> m;
  getchar();
  for (int i = 0; i < n; ++i) {
    temp.clear();
    cin.getline(tt, 2048);
    for (int j = 0; j < strlen(tt); ++j) {
      if (tt[j] == '.') {
        ++j;
        temp.depth += 1;
      } else if (tt[j] == ' ') {
        temp.label = tt + j + 1;
        break;
      } else {
        temp.id += tt[j];
      }
    }
    transform(temp.id.begin(), temp.id.end(), temp.id.begin(), ::tolower);
    ss.push_back(temp);
    // cout<<temp.id<<endl<<temp.label<<temp.depth<<endl;
  }
  for (int i = 0; i < m; ++i) {
    temp.clear();
    cin.getline(tt, 2048);
    sss = tt;
    cut();
    int count = 0;
    vector<int> lines;
    stack<int> front;
    int current = 0;
    for (int i = 0; i < st.size(); ++i) {
      if (st[i][0] != '#') {
        transform(st[i].begin(), st[i].end(), st[i].begin(), ::tolower);
      }
    }
    /*
    if (st.size() == 1) {
      if (st[0][0] == '#') {
        for (int i = 0; i < ss.size(); ++i) {
          if (ss[i].label == st[0]) {
            count++;
            lines.push_back(i + 1);
          }
        }
      } else {
        // transform(st[0].begin(), st[0].end(), st[0].begin(), ::tolower);
        for (int i = 0; i < ss.size(); ++i) {
          if (ss[i].id == st[0]) {
            count++;
            lines.push_back(i + 1);
          }
        }
      }
    } else {
      if (st[0][0] == '#') {
        for (int i = 0; i < ss.size(); ++i) {
          if (st[0] == ss[i].label) {
            front.push(i);
            break;
          }
        }
      } else {
        for (int i = 0; i < ss.size(); ++i) {
          if (st[0] == ss[i].id) {
            front.push(i);
            break;
          }
        }
      }
      current += 1;
      int flag = 0;
      int fff = 0;
      int ff = 0;
      while (front.size()) {
        flag = 0;
        ff = 0;
        fff = 0;
        for (int i = front.top() + 1; i < ss.size(); ++i) {
          if (ss[i].depth > ss[front.top()].depth &&
              (st[current][0] == '#' && st[current] == ss[i].label ||
               st[current] == ss[i].id)) {
            if (current + 1 == st.size()) {
              count += 1;
              lines.push_back(i + 1);
              fff = 1;
            } else {
              front.push(i);
              current += 1;
              flag = 1;
              break;
            }
            flag = 1;
          }
        }
        if (!flag || fff) {
          while (front.size()) {
            current -= 1;
            int t = front.top();
            front.pop();
            for (int i = t + 1; i < ss.size(); ++i) {
              if (ss[i].depth == ss[t].depth &&
                  (st[current][0] == '#' && st[current] == ss[i].label ||
                   st[current] == ss[i].id)) {
                front.push(i);
                current += 1;
                ff = 1;
                break;
              }
            }
            if (ff)
              break;
          }
        }
      }
    }
    */
    for (int i = 0; i < ss.size(); ++i) {
      if (st[st.size() - 1][0] == '#' && st[st.size() - 1] == ss[i].label ||
          st[st.size() - 1] == ss[i].id) {
        int j = st.size() - 2;
        int depth = ss[i].depth;
        int ab = i - 1;
        for (; j>=0; --j) {
          int flag = 0;
          for (; ab>=0; --ab) {
            
            if (depth>ss[ab].depth&&(st[j][0] == '#' && st[j] == ss[ab].label ||
                st[j] == ss[ab].id)) {
              flag = 1;
              depth=ss[ab].depth;
              break;
            }
            depth=min(depth,ss[ab].depth);
          }
          if (!flag)
            break;
        }
        if (j == -1) {
          count++;
          lines.push_back(i + 1);
        }
      }
    }
    sort(lines.begin(), lines.end());
    lines.erase(unique(lines.begin(), lines.end()), lines.end());
    cout << lines.size();
    for (int i = 0; i < lines.size(); ++i) {
      cout << ' ' << lines[i];
    }
    cout << endl;
  }
  return 0;
}