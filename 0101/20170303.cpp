#include <bits/stdc++.h>

using namespace std;
void printline(string src) {
  int a, b, c; //分别表示下划线中括号小括号
  a = b = c = 0;
  for (int i = 0; i < src.size(); ++i) {
    if (src[i] == '_') {
      a ^= 1;
      if (a)
        cout << "<em>";
      else
        cout << "</em>";
    } else if (src[i] == '[') {
      cout << "<a href=\"";
      string text = "";
      string link = "";
      ++i;
      for (; i < src.size() && src[i] != ']'; ++i) {
        text += src[i];
      }
      ++i;
      ++i;
      for (; i < src.size() && src[i] != ')'; ++i) {
        link += src[i];
      }
      for (int j = 0; j < link.size(); ++j) {
        if (link[j] == '_') {
          b ^= 1;
          if (b)
            cout << "<em>";
          else
            cout << "</em>";
        } else
          cout << link[j];
      }
      cout << "\">";
      for (int j = 0; j < text.size(); ++j) {
        if (text[j] == '_') {
          c ^= 1;
          if (c)
            cout << "<em>";
          else
            cout << "</em>";
        } else
          cout << text[j];
      }
      cout << "</a>";
    } else {
      cout << src[i];
    }
  }
}
int main() {
  // freopen("C:\\Users\\32125\\Documents\\vscodec\\0101\\data2.in","r",stdin);
  string temp;
  int state = 0;
  while (getline(cin, temp)) {
    if (temp.empty()) {
      state = 0;
    } else if (temp[0] == '#') {
      int count = 0;
      for (int i = 0; i < temp.size(); ++i) {
        if (temp[i] == '#')
          ++count;
        else
          break;
      }
      int rel = count;
      for (; rel < temp.size(); ++rel) {
        if (temp[rel] != ' ')
          break;
      }
      temp.erase(temp.begin(), temp.begin() + rel);
      cout << "<h" << count << ">";
      printline(temp);
      cout << "</h" << count << ">" << endl;
      state = 0;
    } else if (temp[0] == '*') {
      cout << "<ul>" << endl;
      do {
        int rel = 1;
        for (; rel < temp.size(); ++rel) {
          if (temp[rel] != ' ')
            break;
        }
        temp.erase(temp.begin(), temp.begin() + rel);
        cout << "<li>";
        printline(temp);
        cout << "</li>" << endl;
      } while (getline(cin, temp) && !temp.empty());
      cout << "</ul>" << endl;
      state = 0;
    } else {
      cout << "<p>";
      printline(temp);
      while (getline(cin, temp) && !temp.empty()) {
        cout << endl;
        printline(temp);
      }
      cout << "</p>" << endl;
    }
  }
}