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

  int n, m;
  cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m));
  for (auto &x: a) {
    for (auto &y: x) cin >> y;
  }

  vector<int> r(n), c(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] > r[i]) r[i] = a[i][j];
      if (a[i][j] > c[j]) c[j] = a[i][j];
    }
  }

  sort(r.begin(), r.end());
  sort(c.begin(), c.end());

  vector<vector<int> > ans(n, vector<int>(m));
  vector<bool> used(n*m+1);
  int p1 = 0;
  int p2 = 0;
  while (p1 < n && p2 < m) {
    if (r[p1] == c[p2]) {
      ans[p1][p2] = r[p1];
      used[r[p1]] = true;
      p1++;
      p2++;
    }
    else if (r[p1] < c[p2]) {
      ans[p1][p2] = r[p1];
      used[r[p1]] = true;
      p1++;
    }
    else {
      ans[p1][p2] = c[p2];
      used[c[p2]] = true;
      p2++;
    }
  }

  vector<int> unused;
  for (int i = 1; i <= n*m+1; i++) {
    if (!used[i]) unused.push_back(i);
  }
  p1 = 0;
  p2 = 0;
  int pu = 0;
  while (p1 < n && p2 < m) {
    //cerr << p1 << " " << p2 << endl;
    if (r[p1] <= c[p2]) {
      for (int j = m-1; j >= 0; j--) {
        if (ans[p1][j] == 0) {
          //cerr << "A " << p1 << " " << j << endl;
          ans[p1][j] = unused[pu];
          pu++;
        }
        else break;
      }
      p1++;
    }
    else {
      for (int i = n-1; i >= 0; i--) {
        if (ans[i][p2] == 0) {
          //cerr << "B " << i << " " << p2 << endl;
          ans[i][p2] = unused[pu];
          pu++;
        }
        else break;
      }
      p2++;
    }
  }

  for (auto &x: ans) {
    for (auto &y: x) cout << y << " ";
    cout << endl;
  }

  return 0;
}
