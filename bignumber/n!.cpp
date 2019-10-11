#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 60000;
struct bign
{
    int len, s[maxn];
    bign()
    {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    //将x="123"形式定义
    bign operator=(const char *num)
    {
        len = strlen(num);
        for (int i = 0; i < len; ++i)
            s[i] = num[len - i - 1] - '0';
        return *this;
    }
    //将x=123形式定义
    bign operator=(int num)
    {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    //定义初始化操作
    bign(int num) { *this = num; }
    bign(const char *num) { *this = num; }

    bign operator+(const bign &b) const
    {
        bign c;
        c.len = 0;
        for (int i = 0, g = 0; g || i < max(len, b.len); ++i)
        {
            int x = g;
            if (i < len)
                x += s[i];
            if (i < b.len)
                x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return b;
    }
    void clean()
    {
        while (len > 1 && !s[len - 1])
            len--;
    }
    bign operator*(const bign &b)
    {
        bign c;
        c.len = len + b.len;
        for (int i = 0; i < len; i++)
            for (int j = 0; j < b.len; j++)
                c.s[i + j] += s[i] * b.s[j];
        for (int i = 0; i < c.len - 1; ++i)
        {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bign operator-(const bign &b)
    {
        bign c;
        c.len = 0;
        for (int i = 0, g = 0; i < len; ++i)
        {
            int x = s[i] - g;
            if (i < b.len)
                x -= b.s[i];
            if (x >= 0)
                g = 0;
            else
            {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    bool operator<(const bign &b) const
    {
        if (len != b.len)
            return len < b.len;
        for (int i = len - 1; i >= 0; i--)
            if (s[i] != b.s[i])
                return s[i] < b.s[i];
        return false;
    }

    bool operator>(const bign &b) const
    {
        return b < *this;
    }

    bool operator<=(const bign &b)
    {
        return !(b > *this);
    }

    bool operator==(const bign &b)
    {
        return !(b < *this) && !(*this < b);
    }

    bign operator+=(const bign &b)
    {
        *this = *this + b;
        return *this;
    }

    string str() const
    {
        string res = "";
        for (int i = 0; i < len; ++i)
            res = (char)(s[i] + '0') + res;
        if (res == "")
            res = "0";
        return res;
    }
};
istream &operator>>(istream &in, bign &x)
{
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream &operator<<(ostream &out, const bign &x)
{
    out << x.str();
    return out;
}

int main()
{
    int a;
    bign t = 1;
    map<int, bign> table;
    table[1] = t;
    while (cin >> a)
    {
        int t = 0;
        for (int i = 1; i <= table.size(); ++i)
        {
            if (table.find(i) != table.end())
            {
                if (i <= a)
                    t = i;
                else
                    break;
            }
        }
        bign ans = table[t];
        for (int i = t; i < a; ++i)
        {
            ans = ans * (i + 1);
        }
        table[a] = ans;
        cout <<ans << endl;
    }
    return 0;
}
