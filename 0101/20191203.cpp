#include <bits/stdc++.h>

using namespace std;
int n;
string ss;
int base;
map<string, int> save;
stack<int> op;
stack<int> num;
int geta(string t) {
  if (save[t])
    return save[t];
  else {
    save[t] = base;
    base += 2;
    return base - 2;
  }
}
long long solveone(string t) {
  if (t[0] >= '0' && t[0] <= '9') {
    int j = 0;
    int temp = 0;
    for (j = 0; j < t.size() && t[j] >= '0' && t[j] <= '9'; ++j) {
      temp = temp * 10 + t[j] - '0';
    }
    string tt = t.substr(j, t.size());
    return temp * solveone(tt);
  } else {
    string temp = t[0];
    int front = 1;
    if (2 < t.size() && t[1] >= 'a' && t[1] <= 'z') {
      temp += t[1];
      front = 2;
    }
    int num = geta(temp);
    if (front + 1 < t.size() && t[front] >= '0' && t[front] <= '9') {
      int xi = 0;
      for (; front + 1 < t.size() && t[front] <= '9' && t[front] >= '0';
           ++front) {
        xi = xi * 10 + t[front] - '0';
      }
      num = num * xi;
    }
    if (front + 1 < t.size() && t[front] == '(') {
      int last = front + 1;
      int pei = 1;
      for (; last + 1 < t.size(); ++last) {
        if (t[last] == '(')
          pei += 1;
        else if (t[last] == ')')
          pei -= 1;
        if (!pei)
          break;
      }
      int lastnum=0;
      
      return num+solveone(t.substr(front,pei-front))*
    } else {
      return num + solveone(t.erase(t.begin(), front));
    }
  }
}
long long solve(string t) {
  long long ans = 0;
  int before = 0;
  int pos = 0;
  while (pos != t.npos) {
    before = pos;
    pos = t.find('+');
    string temp = t.substr(before, pos);
    ans += solveone(temp);
  }
  return ans;
}
int main() {
  cin >> n;
  base = 3;
  while (n--) {
    cin >> ss;
    long long a, b;
    int pos = ss.find('=');
    string temp = ss.substr(0, pos);
    a = solve(temp);
    temp = ss.substr(pos, ss.size());
    b = solve(temp);
    if (a == b)
      cout << 'Y' << endl;
    else
      cout << 'N' << endl;
  }
}