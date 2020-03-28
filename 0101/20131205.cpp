#include <iostream>
#include <queue>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

using namespace std;
struct point {
  char con;
  char state = 1;
  char can = 0;

  struct point *up = NULL;
  struct point *down = NULL;
  struct point *left = NULL;
  struct point *right = NULL;
};
int main(int argc, char const *argv[]) {
  int m, n;
  int flag = 0;
  int count = 0;
  int temps;
  queue<struct point *> q;
  struct point source;
  struct point *temp;

  cin >> m >> n;
  point *maps = new point[m * n];
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> maps[i * n + j].con;
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      switch (maps[i * n + j].con) {
      case '.': {
        if (i < m - 1 && (maps[(i + 1) * n + j].con) != '#')
          maps[i * n + j].down = &maps[(i + 1) * n + j];
        break;
      }

      case 'S':
        temps = i * n + j;
      case 'T':
      case '+': {
        if (i < m - 1 && (maps[(i + 1) * n + j].con) != '#')
          maps[i * n + j].down = &maps[(i + 1) * n + j];
        if (i > 0 && maps[(i - 1) * n + j].con != '#')
          maps[i * n + j].up = &maps[(i - 1) * n + j];
      }
      case '-': {
        if (j < n - 1 && maps[i * n + j + 1].con != '#')
          maps[i * n + j].right = &maps[i * n + j + 1];
        if (j > 0 && maps[i * n + j - 1].con != '#')
          maps[i * n + j].left = &maps[i * n + j - 1];
        break;
      }
      case '|': {
        if (i < m - 1 && (maps[(i + 1) * n + j].con) != '#')
          maps[i * n + j].down = &maps[(i + 1) * n + j];
        if (i > 0 && maps[(i - 1) * n + j].con != '#')
          maps[i * n + j].up = &maps[(i - 1) * n + j];
        break;
      }
      default:
        break;
      }
    }
  }
  temp = &maps[temps];
  q.push(temp);
  temp->state = 0;
  while (!q.empty()) {
    temp = q.front();
    temp->can = 1;
    if (temp->con == 'T') {
      flag = 1;
    }
    q.pop();
    struct point *xxx;

    if ((xxx = temp->up) != NULL && xxx->state) {
      q.push(xxx);
      xxx->state = 0;
    }
    if ((xxx = temp->left) != NULL && xxx->state) {
      q.push(xxx);
      xxx->state = 0;
    }
    if ((xxx = temp->down) != NULL && xxx->state) {
      q.push(xxx);
      xxx->state = 0;
    }
    if ((xxx = temp->right) != NULL && xxx->state) {
      q.push(xxx);
      xxx->state = 0;
    }
  }
  if (flag)
    for (int i = 0; i < m * n; i++) {

      if (maps[i].can) {
        int cases = 1;
        for (int j = 0; j < m * n; j++) {
          maps[j].state = 1;
        }
        temp = &maps[i];
        q.push(temp);
        temp->state = 0;
        while (!q.empty()) {
          temp = q.front();
          q.pop();
          if (temp->con == 'T') {
            cases = 0;
          }

          struct point *xxx;

          if ((xxx = temp->up) != NULL && xxx->state) {
            q.push(xxx);
            xxx->state = 0;
          }
          if ((xxx = temp->left) != NULL && xxx->state) {
            q.push(xxx);
            xxx->state = 0;
          }
          if ((xxx = temp->down) != NULL && xxx->state) {
            q.push(xxx);
            xxx->state = 0;
          }
          if ((xxx = temp->right) != NULL && xxx->state) {
            q.push(xxx);
            xxx->state = 0;
          }
        }
        if (cases)
          count++;
      }
    }
  if (flag)
    cout << count;
  else
    cout << "I'm stuck!";
  getchar();
  getchar();
  return 0;
}
