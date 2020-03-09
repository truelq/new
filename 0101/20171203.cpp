#include <bits/stdc++.h>
// 这个题好就好在4的倍数全是闰年,要是有2100年岂不爆炸
using namespace std;
int n;
struct ss {
  int minutes[60];
  int hours[24];
  int day[32];
  int month[13];
  int week[7];
  string command;
  int standard[5][60];
};
int days[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                   0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct date {
  int yyyy;
  int mm;
  int dd;
  int HH;
  int MM;
  int week;
  bool operator<(date &b) {
    if (this->yyyy < b.yyyy)
      return true;
    else if (this->yyyy > b.yyyy)
      return false;
    else {
      if (this->mm < b.mm)
        return true;
      else if (this->mm > b.mm)
        return false;
      else {
        if (this->dd < b.dd)
          return true;
        else if (this->dd > b.dd)
          return false;
        else {
          if (this->HH < b.HH)
            return true;
          else if (this->HH > b.HH)
            return false;
          else {
            if (this->MM < b.MM)
              return true;
            else
              return false;
          }
        }
      }
    }
  }
  void add(int i) {
    MM = MM + i;
    if (MM >= 60) {
      HH += MM / 60;
      MM = MM % 60;
      if (HH >= 24) {
        dd += 1; //仅支持最多加1天
        week += 1;
        week %= 7;
        HH = HH % 24;
        if (dd > days[yyyy % 4 == 0][mm]) {
          dd = 1;
          mm += 1;
          if (mm > 12) {
            yyyy += 1;
            mm = 1;
          }
        }
      }
    }
  }
};

map<string, int> sch;
void init(ss &d, int choice, int l, int r, string src) {
  vector<string> v;
  char te[256] = {0};
  for (int i = 0; i < src.size(); ++i) {
    te[i] = src[i];
  }
  char *sp = strtok(te, ",");
  while (sp) {
    string temp=sp;
    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    v.push_back(temp);
    sp = strtok(NULL, ",");
  }
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == "*") {
      for (int j = l; j <= r; ++j) {
        d.standard[choice][j] = 1;
      }
    } else if (v[i].find('-') != v[i].npos) {
      int k = v[i].find('-');
      string a = v[i].substr(0, k);
      string b = v[i].substr(k + 1, v[i].end() - v[i].begin());
      for (int j = sch[a]; j <= sch[b]; ++j) {
        d.standard[choice][j] = 1;
      }
    } else {
      d.standard[choice][sch[v[i]]] = 1;
    }
  }
}
int main() {
  string s, t;
  date ti[3];
  ss save[25];
  cin >> n >> s >> t;
  string min, hour, day, month, week;
  for (int i = 0; i < 60; ++i) {
    string temp = to_string(i);
    sch[temp] = i;
    temp = "0" + to_string(i);
    sch[temp] = i;
  }
  sch["jan"] = 1;
  sch["feb"] = 2;
  sch["mar"] = 3;
  sch["apr"] = 4;
  sch["may"] = 5;
  sch["jun"] = 6;
  sch["jul"] = 7;
  sch["aug"] = 8;
  sch["sep"] = 9;
  sch["oct"] = 10;
  sch["nov"] = 11;
  sch["dec"] = 12;
  sch["sun"] = 0;
  sch["mon"] = 1;
  sch["tue"] = 2;
  sch["wed"] = 3;
  sch["thu"] = 4;
  sch["fri"] = 5;
  sch["sat"] = 6;
  for (int i = 0; i < n; ++i) {
    cin >> min >> hour >> day >> month >> week;
    cin >> save[i].command;
    init(save[i], 0, 0, 59, min);
    init(save[i], 1, 0, 23, hour);
    init(save[i], 2, 1, 31, day);
    init(save[i], 3, 1, 12, month);
    init(save[i], 4, 0, 6, week);
  }
  ti[0].yyyy = 1970;
  ti[0].mm = 1;
  ti[0].dd = 1;
  ti[0].HH = ti[0].MM = 0;
  ti[0].week = 4;
  ti[1].yyyy = stoi(s.substr(0, 4));
  ti[1].mm = stoi(s.substr(4, 2));
  ti[1].dd = stoi(s.substr(6, 2));
  ti[1].HH = stoi(s.substr(8, 2));
  ti[1].MM = stoi(s.substr(10, 2));
  // ti[1].week = 3;
  ti[2].yyyy = stoi(t.substr(0, 4));
  ti[2].mm = stoi(t.substr(4, 2));
  ti[2].dd = stoi(t.substr(6, 2));
  ti[2].HH = stoi(t.substr(8, 2));
  ti[2].MM = stoi(t.substr(10, 2));
  while (ti[0] < ti[1]) {
    ti[0].add(1);
  }
  int current = 0;
  while (ti[0] < ti[2]) {
    for (int i = 0; i < n; ++i) {
      if (save[i].standard[0][ti[0].MM] && save[i].standard[1][ti[0].HH] &&
          save[i].standard[2][ti[0].dd] && save[i].standard[3][ti[0].mm] &&
          save[i].standard[4][ti[0].week]) {
        printf("%4d%02d%02d%02d%02d", ti[0].yyyy, ti[0].mm, ti[0].dd, ti[0].HH,
               ti[0].MM);
        cout << ' ' << save[i].command << endl;
      }
    }
    ti[0].add(1);
    current += 1;
  }
}