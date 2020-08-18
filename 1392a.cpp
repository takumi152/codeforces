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

  vector<int> ans(t);
  for (int i = 0; i < t; i++) {
    bool allsame = true;
    for (int j = 1; j < n[i]; j++) {
      if (a[i][j] != a[i][0]) allsame = false;
    }
    if (allsame) ans[i] = n[i];
    else ans[i] = 1;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
