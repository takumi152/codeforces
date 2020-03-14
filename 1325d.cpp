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

  ll u, v;
  cin >> u >> v;

  if (u == v) {
    if (u == 0) {
      cout << 0 << endl;
    }
    else {
      cout << 1 << endl;
      cout << u << endl;
    }
    return 0;
  }
  if (u > v) {
    cout << -1 << endl;
    return 0;
  }
  if (u % 2 != v % 2) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> ans;
  ll one = u;
  ll two = (v - u) / 2;
  if (!(one & two)) ans = vector<ll>({one + two, two});
  else ans = vector<ll>({one, two, two});

  cout << ans.size() << endl;
  for (auto &x: ans) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
