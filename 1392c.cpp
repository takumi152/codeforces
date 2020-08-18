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

  int t;
  cin >> t;
  vector<int> n(t);
  vector<vector<int> > a(t);
  for (int i = 0; i < t; i++) {
    cin >> n[i];
    a[i] = vector<int>(n[i]);
    for (auto &x: a[i]) cin >> x;
  }

  vector<ll> ans(t);
  for (int i = 0; i < t; i++) {
    ll added = 0;
    for (int j = 1; j < n[i]; j++) {
      if (a[i][j-1] > a[i][j]) added += a[i][j-1] - a[i][j];
    }
    ans[i] = added;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
