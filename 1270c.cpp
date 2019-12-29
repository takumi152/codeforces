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
  vector<int> n(t);
  vector<vector<ll> > a(t);
  for (int k = 0; k < t; k++) {
    cin >> n[k];
    a[k] = vector<ll>(n[k]);
    for (auto &x: a[k]) cin >> x;
  }

  vector<ll> ans(t);
  vector<vector<ll> > b(t);
  for (int k = 0; k < t; k++) {
    ll sum = 0;
    ll exor = 0;
    for (auto &x: a[k]) {
      sum += x;
      exor ^= x;
    }
    ans[k] = 2;
    b[k] = vector<ll>({exor, sum + exor});
  }

  for (int k = 0; k < t; k++) {
    cout << ans[k] << endl;
    for (auto &x: b[k]) cout << x << " ";
    cout << endl;
  }

  return 0;
}
