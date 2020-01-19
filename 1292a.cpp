#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<Pii> rc(q);
  for (auto &x: rc) {
    cin >> x.first >> x.second;
    x.first--;
    x.second--;
  }

  vector<string> ans(q);
  vector<vector<bool> > board(2, vector<bool>(n));
  int block = 0;
  for (int i = 0; i < q; i++) {
    if (!board[rc[i].first][rc[i].second]) {
      board[rc[i].first][rc[i].second] = true;
      int r = rc[i].first ^ 1;
      for (int c = rc[i].second - 1; c <= rc[i].second + 1; c++) {
        if (c < 0 || c >= n) continue;
        if (board[r][c]) block++;
      }
    }
    else {
      board[rc[i].first][rc[i].second] = false;
      int r = rc[i].first ^ 1;
      for (int c = rc[i].second - 1; c <= rc[i].second + 1; c++) {
        if (c < 0 || c >= n) continue;
        if (board[r][c]) block--;
      }
    }
    if (block == 0) ans[i] = "Yes";
    else ans[i] = "No";
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
