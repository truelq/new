#include <bits/stdc++.h>

using namespace std;
long long mod = 100000007;
string ss[30];
stack<long long> num;
stack<char> op;
long long lev[256];

long long p(long long a, long long b) {
  if (a == 0)
    return 0;
  long long s = 1;
  long long tt = a;
  while (b > 0) {
    if (b % 2 == 1) {
      s = (s * tt)%mod;
    }
    tt = (tt * tt)%mod;
    b /= 2;
  }
  return s;
}

long long calc() {

  char ts = op.top();
  op.pop();
  long long t1 = num.top();
  num.pop();
  long long t2 = num.top();
  num.pop();
  long long ans = 0;
  if (ts == '-')
    ans = t2 - t1+mod;
  else if (ts == '+')
    ans = t1 + t2;
  else if (ts == '*')
    ans = t2 * t1;
  else if (ts == '^')
    ans = p(t2, t1);
  num.push(ans%mod);
  return 0;
}
long long solve(string &base, long long a) {
  long long k = 0;
  long long temp = 0;
  while (op.size())
    op.pop();
  while (num.size()) {
    num.pop();
  }

  op.push('#');
  for (long long i = 0; i < base.size(); ++i) {
    if (base[i] == 'a')
      num.push(a);
    else if (base[i] <= '9' && base[i] >= '0') {
      temp = (temp * 10 + base[i] - '0');
      if (i + 1 < base.size() && (base[i + 1] < '0' || base[i + 1] > '9')) {
        num.push(temp);
        temp = 0;
      } else if (i + 1 == base.size()) {
        num.push(temp);
      }
    } else if (base[i] == '(') {
      op.push('(');
      ++k;
    } else if (base[i] == ')') {
      if (k <= 0)
        return -1;
      while (op.top() != '(')
        calc();
      op.pop(); //匹配
      --k;
    } else if (base[i] != ' ') {
      char tp = op.top();
      while (lev[(unsigned long long)base[i]] <= lev[(unsigned long long)tp]) {
        calc();
        tp = op.top();
      }
      op.push(base[i]);
    }
  }
  if (k > 0)
    return -1;
  while (op.top() != '#')
    calc();
  return num.top();
}
int main() {
  lev[(unsigned long long)'#'] = 0;
  lev[(unsigned long long)'+'] = 1;
  lev[(unsigned long long)'-'] = 1;
  lev[(unsigned long long)'*'] = 2;
  lev[(unsigned long long)'^'] = 3;
  string base;
  getline(cin, base, '\r');
  getchar();
  long long n;
  cin >> n;
  string ssss;
  getline(cin, ssss, '\r');
  getchar();
  for (long long i = 0; i < n; ++i) {
    getline(cin, ss[i], '\r');
    getchar();
  }
  long long basea = solve(base, 3);
  long long baseb = solve(base, 137);
  char b[26];
  for (long long i = 0; i < 26; ++i)
    b[i] = i + 'A';
  for (long long i = 0; i < n; ++i) {
    if (solve(ss[i], 3) == basea && solve(ss[i], 137) == baseb)
      cout << b[i];
  }
}