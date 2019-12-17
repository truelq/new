#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string base;
string ss[27];
long long x = 3;
int n;
int lev[256];
stack<int> number;
stack<char> op;

long long powermod(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      ans = ans * a;
      ans %= MOD;
    }
    a = a * a;
    a %= MOD;
  }
  return ans;
}
void calc() {
  char ts = op.top();
  op.pop();
  long long t1 = number.top();
  number.pop();
  long long t2 = number.top();
  number.pop();
  if (ts == '+')
    number.push((t1 + t2) % MOD);
  else if (ts == '-')
    number.push((t2 - t1 + MOD) % MOD);
  else if (ts == '*')
    number.push((t1 * t2) % MOD);
  else if (ts == '^')
    number.push(powermod(t2, t1) % MOD);
}
long long solve(string &a) {
  int k = 0;
  op.push('#');
  long long temp = 0;
  for (int i = 0; a[i] != '\n' && a[i] != '\r' && a[i] != 0 && i < a.size();
       ++i) {
    if (a[i] == 'a')
      number.push(x);
    else if (a[i] <= '9' && a[i] >= '0') {
      temp = (temp * 10 + a[i] - '0') % MOD;
      if (i==a.size()||a[i + 1] == '\n' || a[i + 1] == '\r' || a[i + 1] == 0 ||
          (a[i + 1] < '0' || a[i + 1] > '9')) {
        number.push(temp);
        temp = 0;
      }
    } else if (a[i] == '(') {
      op.push('(');
      ++k;
    } else if (a[i] == ')') {
        if(k<=0)
        return -1;
      while (op.top() != '(') {
        calc();
      }
      op.pop();
      --k;
    } else if (a[i] == ' '||a[i]=='\r'||a[i]=='\t'||a[i]=='\n'||a[i]==0) {
      continue;
    } else {
      int tt = op.top();
      while (lev[a[i]] <= lev[tt]) {
        calc();
        tt = op.top();
      }
      op.push(a[i]);
    }
  }
  while (op.top() != '#') {
    calc();
  }
  return number.top();
}
int main() {
  getline(cin, base);
  cin >> n;
  string ot;
  getline(cin,ot);
  for (int i = 0; i < n; ++i) {
    getline(cin, ss[i]);
    // cin >> ss[i];
  }
  x = 3;
  lev['#'] = 0;
  lev['+'] = lev['-'] = 1;
  lev['*'] = lev['/'] = 2;
  lev['^'] = 3;

  long long tempa = solve(base);
  number.pop();
  op.pop();
  for (int i = 0; i < n; ++i) {
    if (tempa == solve(ss[i])) {
      printf("%c", i + 'A');
    }
    while(number.size())
    number.pop();
    while(op.size())
    op.pop();
  }
  return 0;
}