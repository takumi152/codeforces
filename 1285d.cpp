// WA

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

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) cin >> x;

  for (int i = (1 << 30); i > 0; i >>= 1) {
    sort(a.rbegin(), a.rend());
    vector<int> flipV = a;
    for (auto &x: flipV) x ^= i;
    sort(flipV.rbegin(), flipV.rend());
    bool shouldFlip = false;
    for (int j = 0; j < n; j++) {
      if (a[j] < flipV[j]) break;
      else if (a[j] > flipV[j]) {
        shouldFlip = true;
        break;
      }
    }
    if (shouldFlip) a = flipV;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > ans) ans = a[i];
  }

  cout << ans << endl;

  return 0;
}
