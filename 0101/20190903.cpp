#include <bits/stdc++.h>

using namespace std;
int m, n, p, q;
struct ssa {
  int r, g, b;
};
bool operator==(ssa &a, ssa &b) {
  return a.r == b.r && a.g == b.g && a.b == b.b;
}

void to_ssa(string &temp, ssa &d) {
  if (temp.size() == 2) {
    d.r = d.g = d.b = (temp[1] >= '0' && temp[1] <= '9') ? (temp[1] - '0') * 17
                                                         : (temp[1] - 'a'+10) * 17;
  } else if (temp.size() == 4) {
    d.r = temp[1] >= '0' && temp[1] <= '9' ? (temp[1] - '0') * 17
                                           : (temp[1] - 'a'+10) * 17;
    d.g = temp[2] >= '0' && temp[2] <= '9' ? (temp[2] - '0') * 17
                                           : (temp[2] - 'a'+10) * 17;
    d.b = temp[3] >= '0' && temp[3] <= '9' ? (temp[3] - '0') * 17
                                           : (temp[3] - 'a'+10) * 17;
  } else {
    d.r = ((temp[1] >= '0' && temp[1] <= '9') ? (temp[1] - '0') * 16
                                              : ((temp[1] - 'a'+10) * 16)) +
          ((temp[2] >= '0' && temp[2] <= '9') ? (temp[2] - '0')
                                              : (temp[2] - 'a'+10));
    d.g = ((temp[3] >= '0' && temp[3] <= '9') ? (temp[3] - '0') * 16
                                              : ((temp[3] - 'a'+10) * 16)) +
          ((temp[4] >= '0' && temp[4] <= '9') ? (temp[4] - '0')
                                              : (temp[4] - 'a'+10));
    d.b = ((temp[5] >= '0' && temp[5] <= '9') ? (temp[5] - '0') * 16
                                              : ((temp[5] - 'a'+10) * 16)) +
          ((temp[6] >= '0' && temp[6] <= '9') ? (temp[6] - '0')
                                              : (temp[6] - 'a'+10));
  }
}
ssa ss[2000][2000];
ssa sss[2000][2000];
ssa background = {0, 0, 0};
ssa fg = {255, 255, 255};
string base = "\\x1B\\x5B";
string default_base = "\\x1B\\x5B\\x30\\x6D";
string space = "\\x20";
void print_front(string &r, string &g, string &b) {
  cout << base << "\\x33\\x38\\x3B\\x32\\x3B" << r << "\\x3B" << g << "\\x3B"
       << b << "\\x6D";
}
void print_back(string &r, string &g, string &b) {
  cout << base << "\\x34\\x38\\x3B\\x32\\x3B" << r << "\\x3B" << g << "\\x3B"
       << b << "\\x6D";
}
string to_a(int b) {
  string temp = "";
  /*
  if (b < 16) {
    if (b < 10) {
      return temp + "\\x3" + (char)(b % 10 + '0');
    } else {
      return temp + "\\x4" + (char)('A' + b - 10);
    }
  } else {
    return to_a(b / 16) + to_a(b % 16);
  }*/
  if (b < 10) {
    return temp + "\\x3" + (char)(b % 10 + '0');
  } else if (b < 100) {
    return to_a(b / 10) + to_a(b % 10);
  } else {
    return to_a(b / 100) + to_a(b % 100 / 10) + to_a(b % 10);
  }
}
int main() {
  cin >> m >> n >> p >> q;
  int w = m / p;
  int h = n / q;
  string temp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> temp;
      to_ssa(temp, ss[i][j]);
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (int k = 0; k < q; ++k) {
        for (int t = 0; t < p; ++t) {
          sss[i][j].r += ss[i * q + k][j * p + t].r;
          sss[i][j].g += ss[i * q + k][j * p + t].g;
          sss[i][j].b += ss[i * q + k][j * p + t].b;
        }
      }
      sss[i][j].r = sss[i][j].r / (p * q);
      sss[i][j].g = sss[i][j].g / (p * q);
      sss[i][j].b = sss[i][j].b / (p * q);
    }
  }
  ssa last = background;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (sss[i][j] == last) {
        cout << space;
      } else if (sss[i][j] == background) {
        cout << default_base;
        cout << space;
      } else {
        string r = to_a(sss[i][j].r);
        string g = to_a(sss[i][j].g);
        string b = to_a(sss[i][j].b);
        print_back(r, g, b);
        cout << space;
      }
      last = sss[i][j];
    }
    if (last == background) {
      int a = 1;
    } else {
      last = background;
      cout << default_base;
    }
    cout << "\\x0A";
  }
  return 0;
}