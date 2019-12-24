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
  vector<int> a(t), b(t), c(t), r(t);
  for (int i = 0; i < t; i++) cin >> a[i] >> b[i] >> c[i] >> r[i];

  vector<int> ans(t);
  for (int k = 0; k < t; k++) {
    if (a[k] > b[k]) swap(a[k], b[k]);
    int alpha = 0, beta = 0;
    if (c[k] < a[k]) alpha = min(b[k] - a[k], max(0, b[k] - c[k] - r[k]));
    else if (b[k] < c[k]) beta = min(b[k] - a[k], max(0, c[k] - a[k] - r[k]));
    else {
      alpha = max(0, c[k] - a[k] - r[k]);
      beta = max(0, b[k] - c[k] - r[k]);
    }
    ans[k] = alpha + beta;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
