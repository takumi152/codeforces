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
  vector<int> n(t), k1(t), k2(t);
  vector<vector<int> > a(t), b(t);
  for (int k = 0; k < t; k++) {
    cin >> n[k] >> k1[k] >> k2[k];
    a[k] = vector<int>(k1[k]);
    b[k] = vector<int>(k2[k]);
    for (auto &x: a[k]) cin >> x;
    for (auto &x: b[k]) cin >> x;
  }

  vector<string> ans(t);
  for (int k = 0; k < t; k++) {
    bool firstwin = false;
    for (auto &x: a[k]) {
      if (x == n[k]) {
        firstwin = true;
        break;
      }
    }
    if (firstwin) ans[k] = "YES";
    else ans[k] = "NO";
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
