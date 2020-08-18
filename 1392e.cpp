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

  int n;
  cin >> n;

  vector<vector<ll> > a(n, vector<ll>(n));
  a[1][0] = 1;
  for (int i = 2; i < n; i++) a[i][0] = a[i-1][0] * 2;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) a[i][j] = a[i-1][j] + a[i][j-1];
  }

  vector<vector<ll> > minimum(n, vector<ll>(n));
  vector<vector<ll> > maximum(n, vector<ll>(n));
  for (int i = 1; i < n; i++) {
    minimum[i][0] = a[i][0] - 1;
    maximum[i][0] = a[i][0] - 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      minimum[i][j] = minimum[i-1][j] + a[i-1][j];
      maximum[i][j] = maximum[i][j-1] + a[i][j-1];
    }
  }

  for (auto &x: a) {
    for (auto &y: x) cout << y << " ";
    cout << endl;
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    ll k;
    cin >> k;

    vector<Pii> ans;
    int x = n-1;
    int y = n-1;
    while (x > 0 || y > 0) {
      ans.emplace_back(x+1, y+1);
      if (x == 0) y--;
      else if (y == 0) x--;
      else {
        k -= a[x][y];
        cerr << k << " " << minimum[x][y-1] << " " << a[x][y-1] << " " << x << " " << y << endl;
        if (k >= minimum[x][y-1] + a[x][y-1]) y--;
        else x--;
      }
    }
    ans.emplace_back(x+1, y+1);

    reverse(ans.begin(), ans.end());
    for (auto &z: ans) cout << z.first << " " << z.second << endl;
  }

  return 0;
}
