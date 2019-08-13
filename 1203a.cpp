#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  vector<int> n(q);
  vector<vector<int> > p(q);
  for (int i = 0; i < q; i++) {
    cin >> n[i];
    p[i].assign(n[i], 0);
    for (auto &x: p[i]) cin >> x;
  }

  vector<string> ans(q);
  for (int i = 0; i < q; i++) {
    if (n[i] <= 2) {
      ans[i] = "YES";
      continue;
    }
    if (p[i][0]+1 == p[i][1] || (p[i][0] == n[i] && p[i][1] == 1)) {
      for (int j = 0; j < n[i]-1; j++) {
        if (!(p[i][j]+1 == p[i][j+1] || (p[i][j] == n[i] && p[i][j+1] == 1))) {
          ans[i] = "NO";
          break;
        }
      }
    }
    else if (p[i][1]+1 == p[i][0] || (p[i][1] == n[i] && p[i][0] == 1)) {
      for (int j = 0; j < n[i]-1; j++) {
        if (!(p[i][j+1]+1 == p[i][j] || (p[i][j+1] == n[i] && p[i][j] == 1))) {
          ans[i] = "NO";
          break;
        }
      }
    }
    else {
      ans[i] = "NO";
    }
    if (ans[i] != "NO") ans[i] = "YES";
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
