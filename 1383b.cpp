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

  vector<string> ans(t);
  for (int i = 0; i < t; i++) {
    bool confirmed = false;
    for (int j = (1 << 30); j != 0; j >>= 1) {
      int bitCount = 0;
      for (int k = 0; k < n[i]; k++) {
        if (a[i][k] & j) bitCount++;
      }
      if (bitCount % 2 == 0) continue;
      else if (bitCount % 4 == 1 || (bitCount % 4 == 3 && n[i] % 2 == 0)) {
        ans[i] = "WIN";
        confirmed = true;
        break;
      }
      else if (bitCount % 4 == 3) {
        ans[i] = "LOSE";
        confirmed = true;
        break;
      }
    }
    if (!confirmed) ans[i] = "DRAW";
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
