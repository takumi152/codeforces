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

  int n;
  cin >> n;
  vector<ll> b(n);
  for (auto &x: b) cin >> x;

  vector<ll> a(n);
  ll maximum = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] < 0) {
      a[i] = maximum + b[i];
    }
    else {
      a[i] = maximum + b[i];
      maximum = a[i];
    }
  }

  for (auto &x: a) cout << x << " ";
  cout << endl;

  return 0;
}
