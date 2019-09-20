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
const ll INF = (ll) 2e18;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  vector<int> n(q);
  vector<vector<ll> > a(q), b(q);
  for (int i = 0; i < q; i++) {
    cin >> n[i];
    a[i] = vector<ll>(n[i]);
    b[i] = vector<ll>(n[i]);
    for (int j = 0; j < n[i]; j++) cin >> a[i][j] >> b[i][j];
  }

  vector<ll> ans(q);

  for (int t = 0; t < q; t++) {
    vector<vector<vector<ll> > > dp(3, vector<vector<ll> >(3, vector<ll>(n[t] + 2)));
    for (int i = 0; i < 3; i++) dp[i][0][0] = 0;
    for (int i = 0; i < 3; i++) dp[i][1][0] = dp[0][1][0] + b[t][0];
    for (int i = 0; i < 3; i++) dp[i][2][0] = dp[0][2][0] + b[t][0];
    for (int k = 1; k < n[t]; k++) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          ll f = min(min(dp[0][i][k-1], dp[1][i][k-1]), dp[2][i][k-1]);
          if (a[t][k-1] + i == a[t][k] + j) f += INF;
          dp[i][j][k] = f + b[t][k] * j;
        }
      }
    }
    ll smallest = INF;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (dp[i][j][n[t]-1] < smallest) smallest = dp[i][j][n[t]-1];
      }
    }
    ans[t] = smallest;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
