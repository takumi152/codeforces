#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x: a) cin >> x;

  bool hasZero = false;
  for (auto &x: a) {
    if (x == 0) {
      hasZero = true;
    }
  }
  ll cost = 0;
  int negativeOne = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      cost += a[i] - 1;
    }
    else if (a[i] < 0) {
      cost += -a[i] - 1;
      negativeOne++;
    }
    else {
      cost++;
    }
  }
  if (negativeOne % 2 == 1 && !hasZero) {
    cost += 2;
  }

  cout << cost << endl;

  return 0;
}
