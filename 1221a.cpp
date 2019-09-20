#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  vector<int> n(q);
  vector<vector<int> > s(q);
  for (int i = 0; i < q; i++) {
    cin >> n[i];
    s[i] = vector<int>(n[i]);
    for (auto &x: s[i]) cin >> x;
  }

  vector<string> ans(q);
  for (int t = 0; t < q; t++) {
    int total = 0;
    for (auto &x: s[t]) {
      if (x <= 2048) total += x;
    }
    if (total >= 2048) ans[t] = "Yes";
    else ans[t] = "No";
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
