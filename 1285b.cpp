#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  vector<int> n(t);
  vector<vector<ll> > a(t);
  for (int k = 0; k < t; k++) {
    cin >> n[k];
    a[k] = vector<ll>(n[k]);
    for (auto &x: a[k]) cin >> x;
  }

  vector<string> ans(t);
  for (int k = 0; k < t; k++) {
    ll total = 0;
    for (auto &x: a[k]) total += x;
    ll maximum = (ll) -9e18;
    vector<ll> dp(n[k]+2);
    for (int i = 0; i < n[k]-1; i++) {
      dp[i+1] = max(dp[i] + a[k][i], 0LL);
      if (dp[i+1] > maximum) maximum = dp[i+1];
    }
    dp = vector<ll>(n[k]+2);
    for (int i = 1; i < n[k]; i++) {
      dp[i+1] = max(dp[i] + a[k][i], 0LL);
      if (dp[i+1] > maximum) maximum = dp[i+1];
    }
    if (maximum >= total) ans[k] = "No";
    else ans[k] = "Yes";
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
