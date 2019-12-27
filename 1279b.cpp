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
  vector<int> n(t), s(t);
  vector<vector<int> > a(t);
  for (int k = 0; k < t; k++) {
    cin >> n[k] >> s[k];
    a[k] = vector<int>(n[k]);
    for (auto &x: a[k]) cin >> x;
  }

  vector<int> ans(t);
  for (int k = 0; k < t; k++) {
    int elapsed = 0;
    int p = 0;
    int longest = 0;
    int idx = 0;
    while (p < n[k]) {
      elapsed += a[k][p];
      if (elapsed > s[k]) break;
      if (a[k][p] > longest) {
        longest = a[k][p];
        idx = p;
      }
      p++;
    }
    if (p == n[k]) ans[k] = 0;
    else {
      if (a[k][p] < longest) ans[k] = idx+1;
      else ans[k] = p+1;
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
