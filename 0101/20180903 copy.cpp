#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 105;

struct Node {
  string lable, id; //标签和属性
  int cnt;          //缩进
} a[N];

//将字符串化成小写
void mystrlwr(string &s) {
  for (int i = 0; i < s.length(); i++)
    s[i] = tolower(s[i]);
}

//在数组a中[1,start]寻找缩进小于cnt,且标签或属性等于s的元素
bool search(Node a[], int &start, int &cnt, string s) {
  for (int i = start; i >= 1; i--) //遍历
  {
    if (a[i].cnt < cnt) {
      //查询成功
      cnt = a[i].cnt, start = i; //保证a[i]是它的父亲，即第一个缩进小于它的元素
      if (s == a[i].lable || s == a[i].id)
        return true; //成功
    }
  }
  return false; //查询失败
}

int main() {
  int n, m;
  string s;
  cin >> n >> m; //读入n和m
  getchar();     //读取换行符
  for (int i = 1; i <= n; i++) {
    getline(cin, s);
    // pos1记录标签的起始位置，pos2记录id属性的起始位置，cnt记录缩进
    int pos1 = -1, pos2 = -1, cnt = 0;
    for (int j = 0; j < s.length(); j++)
      if (s[j] == '.')
        cnt++;
      else if (pos1 == -1 && s[j] != '#')
        pos1 = j;
      else if (s[j] == '#')
        pos2 = j;
    a[i].cnt = cnt;
    if (pos2 == -1) //如果不存在id属性
    {
      a[i].lable = s.substr(pos1);
      a[i].id = ""; //置为空
    } else          //存在id属性
    {
      a[i].lable = s.substr(pos1, pos2 - pos1 - 1);
      a[i].id = s.substr(pos2);
    }
    mystrlwr(a[i].lable); //由于标签属性大小写不敏感，因此统一换成小写
  }
  for (int i = 0; i < m; i++) //读入m个查询
  {
    char tmp[100];
    vector<string> query; //存储查询
    vector<int> ans;      //存储结果
    gets(tmp);            //读入
    char *sp = strtok(tmp, " "); //将插叙用空格分割，按序存放在query向量中
    while (sp) {
      query.push_back(sp);
      sp = strtok(NULL, " ");
    }
    int len = query.size();
    for (int j = 0; j < len; j++) //将标签统一化成小写
      if (query[j][0] != '#')
        mystrlwr(query[j]);
    for (int j = 1; j <= n; j++) //遍历n行元素
    {
      if (query[len - 1] == a[j].id ||
          query[len - 1] == a[j].lable) //最后一级选择器匹配了
      {
        int start = j, cnt = a[j].cnt,
            k = len - 2; //使用search函数匹配各级父选择器
        for (; k >= 0; k--) {
          if (!search(a, start, cnt, query[k]))
            break;
        }
        if (k < 0) //成功
          ans.push_back(j);
      }
    }
    //输出结果
    cout << ans.size();
    for (int j = 0; j < ans.size(); j++)
      cout << " " << ans[j];
    cout << endl;
  }
  return 0;
}
