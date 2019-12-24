#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<bool> > board(n, vector<bool>(n));
  vector<vector<bool> > visited(n, vector<bool>(n));
  queue<Pii> que;
  que.emplace(0, 0);
  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    int x = now.first;
    int y = now.second;
    if (visited[x][y]) continue;
    visited[x][y] = true;
    if (x - 2 >= 0) {
      if (y - 1 >= 0) {
        board[x-2][y-1] = !board[x][y];
        que.emplace(x-2, y-1);
      }
      if (y + 1 < n) {
        board[x-2][y+1] = !board[x][y];
        que.emplace(x-2, y+1);
      }
    }
    if (x - 1 >= 0) {
      if (y - 2 >= 0) {
        board[x-1][y-2] = !board[x][y];
        que.emplace(x-1, y-2);
      }
      if (y + 2 < n) {
        board[x-1][y+2] = !board[x][y];
        que.emplace(x-1, y+2);
      }
    }
    if (x + 1 < n) {
      if (y - 2 >= 0) {
        board[x+1][y-2] = !board[x][y];
        que.emplace(x+1, y-2);
      }
      if (y + 2 < n) {
        board[x+1][y+2] = !board[x][y];
        que.emplace(x+1, y+2);
      }
    }
    if (x + 2 < n) {
      if (y - 1 >= 0) {
        board[x+2][y-1] = !board[x][y];
        que.emplace(x+2, y-1);
      }
      if (y + 1 < n) {
        board[x+2][y+1] = !board[x][y];
        que.emplace(x+2, y+1);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j]) cout << "W";
      else cout << "B";
    }
    cout << endl;
  }

  return 0;
}
