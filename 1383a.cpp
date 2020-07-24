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
  vector<string> a(t), b(t);
  for (int i = 0; i < t; i++) {
    cin >> n[i];
    cin >> a[i];
    cin >> b[i];
  }

  vector<int> ans(t);
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < n[i]; j++) {
      if (a[i][j] > b[i][j]) {
        ans[i] = -1;
        break;
      }
    }
    if (ans[i] == -1) continue;

    while (true) {
      char smallest_a = 'u';
      char smallest_b = 'u';
      for (int j = 0; j < n[i]; j++) {
        if (a[i][j] < b[i][j]) {
          if (a[i][j] < smallest_a) {
            smallest_a = a[i][j];
            smallest_b = b[i][j];
          }
          else if (a[i][j] == smallest_a && b[i][j] < smallest_b) {
            smallest_b = b[i][j];
          }
        }
      }
      if (smallest_b == 'u') break;
      for (int j = 0; j < n[i]; j++) {
        if (a[i][j] == smallest_a && a[i][j] != b[i][j]) a[i][j] = smallest_b;
      }
      //cerr << i << " " << ans[i] << " " << a[i] << " " << b[i] << endl;
      ans[i]++;
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
