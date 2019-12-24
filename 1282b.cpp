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
  vector<int> n(t), p(t), k(t);
  vector<vector<int> > a(t);
  for (int i = 0; i < t; i++) {
    cin >> n[i] >> p[i] >> k[i];
    a[i] = vector<int>(n[i]);
    for (auto &x: a[i]) cin >> x;
  }

  vector<int> ans(t);
  for (int s = 0; s < t; s++) {
    sort(a[s].begin(), a[s].end());
    vector<int> dp1(n[s]+1), dp2(n[s]+1);
    for (int i = 0; i < n[s]; i++) {
      dp1[i+1] = dp1[i] + a[s][i];
      if (i < k[s]-1) dp2[i+1] = dp1[i+1];
      else dp2[i+1] = min(min(dp1[i+1-k[s]], dp2[i+1-k[s]]) + a[s][i], dp1[i+1]);
    }
    int best = 0;
    for (int i = 0; i <= n[s]; i++) {
      if (dp2[i] <= p[s]) best = i;
    }
    ans[s] = best;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
