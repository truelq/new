#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 0;
    char k;
    string isbn;
    string temp;
    cin >> temp;
    isbn = temp;
    temp.erase(11, 1);
    temp.erase(5, 1);
    temp.erase(1, 1);
    for (int i = 0; i < temp.size() - 1; ++i) {
        a += (temp[i]-'0') * (i + 1);
    }
    a = a % 11;
    if (a == 10)
        k = 'X';
    else
        k = '0' + a;
    if (k == temp[temp.size() - 1])
        cout << "Right";
    else {
        isbn[isbn.size() - 1] = k;
        cout << isbn;
    }
    return 0;
}