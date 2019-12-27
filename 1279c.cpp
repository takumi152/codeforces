#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  vector<int> n(t), m(t);
  vector<vector<int> > a(t), b(t);
  for (int k = 0; k < t; k++) {
    cin >> n[k] >> m[k];
    a[k] = vector<int>(n[k]);
    b[k] = vector<int>(m[k]);
    for (auto &x: a[k]) cin >> x;
    for (auto &x: b[k]) cin >> x;
  }

  vector<ll> ans(t);
  for (int k = 0; k < t; k++) {
    unordered_set<int> taken;
    ll elapsed = 0;
    int p = 0;
    for (int i = 0; i < m[k]; i++) {
      auto it = taken.find(b[k][i]);
      if (it == taken.end()) {
        elapsed += taken.size() * 2;
        while (p < n[k]) {
          if (a[k][p] != b[k][i]) {
            taken.insert(a[k][p]);
            p++;
            elapsed += 2;
          }
          else {
            p++;
            break;
          }
        }
      }
      else {
        taken.erase(it);
      }
      elapsed++;
    }
    ans[k] = elapsed;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
