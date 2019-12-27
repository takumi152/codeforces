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
  vector<vector<int> > rgb(t, vector<int>(3));
  for (auto &x: rgb) cin >> x[0] >> x[1] >> x[2];

  vector<string> ans(t);
  for (int k = 0; k < t; k++) {
    sort(rgb[k].begin(), rgb[k].end());
    if (rgb[k][2] <= rgb[k][0] + rgb[k][1] + 1) {
      ans[k] = "Yes";
    }
    else {
      ans[k] = "No";
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
