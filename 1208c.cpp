#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<vector<int> > ans(n, vector<int>(n));
  for (int i = 0; i < n; i += 4) {
    for (int j = 0; j < n; j += 4) {
      for (int s = 0; s < 4; s++) {
        for (int t = 0; t < 4; t++) {
          ans[i+s][j+t] = i * n + j * 4 + s * 4 + t;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j];
      if (j < n-1) cout << " ";
      else cout << endl;
    }
  }

  return 0;
}
