#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int m, n;
  int k;
  int witch = -1;
  int state;
  cin >> n >> m;
  char temp;
  string all;
  string obj;
  string tempkey = "default";
  string tempvalue;
  string tempstring;
  all.reserve(80 * 100);
  string ques[m];

  unordered_map<string, unordered_map<string, string>> OBJECT;
  getchar();
  for (int i = 0; i < n; ++i) {
    while ((temp = getchar()) != '\n') {
      if (temp != ' ' && temp != '\t' && temp != '\r')
        all += temp;
    }
  }
  for (int i = 0; i < m; ++i)
  // cin >> ques[i];
  {
    while ((temp = getchar()) != '\n')
      if (temp != '\r')
        ques[i] += temp;
  }
  for (int i = 0; i < all.size(); ++i) {
    if (all[i] == '{')
      witch = 1;
    else if (all[i] == '"')
      witch = 2;
    else if (all[i] == '}')
      witch = 3;
    else
      continue;
    tempstring.clear();
    switch (witch) {
    case 1:
      obj = obj + '.' + tempkey;
      state = 1;
      OBJECT[obj][""] = "";
      tempkey.clear();
      tempvalue.clear();
      break;
    case 2:
      tempstring.clear();
      tempvalue.clear();
      if (state) {
        for (int j = i + 1; j < all.size(); ++j) {
          if (all[j] == '\\')
            ++j;
          else if (all[j] == '"') {
            i = j;
            break;
          }
          tempstring += all[j];
        }
        while (all[i] != ':')
          ++i;
        tempkey = tempstring;
        state = 0;
      } else {
        for (int j = i + 1; j < all.size(); ++j) {
          if (all[j] == '\\')
            ++j;
          else if (all[j] == '"') {
            i = j;
            break;
          }
          tempstring += all[j];
        }
        tempvalue = tempstring;
        OBJECT[obj][tempkey] = tempvalue;
        state = 1;
      }
      break;
    case 3:
      for (int j = 0; j < obj.size(); ++j) {
        if (obj[j] == '.')
          k = j;
      }
      obj.erase(k);
      break;
    default:
      break;
    }
  }

  for (int i = 0; i < m; ++i) {
    obj = ".default";
    if (!OBJECT[obj][ques[i]].empty())
      printf("STRING %s\n", OBJECT[obj][ques[i]].data());
    // cout<<"STRING "<<OBJECT[obj][ques[i]]<<endl;
    else {
      obj += '.' + ques[i];
      if (!OBJECT[obj].empty())
        printf("OBJECT\n");
      // cout<<"OBJECT"<<endl;
      else {
        for (int j = 0; j < obj.size(); ++j) {
          if (obj[j] == '.')
            k = j;
        }
        tempkey.clear();
        for (int j = k + 1; j < obj.size(); ++j)
          tempkey += obj[j];
        obj.erase(k);
        if (!OBJECT[obj][tempkey].empty())
          printf("STRING %s\n", OBJECT[obj][tempkey].data());
        // cout << "STRING " << OBJECT[obj][tempkey] << endl;
        else
          printf("NOTEXIST\n");
        // cout << "NOTEXIST" << endl;
      }
    }
  }
  return 0;
}