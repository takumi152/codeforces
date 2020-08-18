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
  vector<ll> n(t), k(t);
  vector<vector<int> > a(t);
  for (int i = 0; i < t; i++) {
    cin >> n[i] >> k[i];
    a[i] = vector<int>(n[i]);
    for (auto &x: a[i]) cin >> x;
  }

  vector<vector<int> > ans(t);
  for (int i = 0; i < t; i++) {
    vector<int> odd(n[i]), even(n[i]);

    int d1 = -1000000007;
    for (int j = 0; j < n[i]; j++) d1 = max(d1, a[i][j]);
    for (int j = 0; j < n[i]; j++) odd[j] = d1 - a[i][j];


    int d2 = -1000000007;
    for (int j = 0; j < n[i]; j++) d2 = max(d2, odd[j]);
    for (int j = 0; j < n[i]; j++) even[j] = d2 - odd[j];

    if (k[i] % 2 == 0) ans[i] = even;
    else ans[i] = odd;
  }

  for (auto &x: ans) {
    for (auto &y: x) cout << y << " ";
    cout << endl;
  }

  return 0;
}
