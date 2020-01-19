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

  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  ll xs, ys, t;
  cin >> xs >> ys >> t;

  vector<pair<ll, ll> > point;
  point.emplace_back(x0, y0);
  ll xp = x0;
  ll yp = y0;
  while (xp <= (ll) 2e16 && yp <= (ll) 2e16) {
    xp = (ax * xp) + bx;
    yp = (ay * yp) + by;
    point.emplace_back(xp, yp);
  }

  int n = point.size();

  int ans = 0;
  for (int i = 0; i < n; i++) { // head
    for (int j = i; j < n; j++) { // first
      for (int k = j; k < n; k++) { // tail
        if (ans >= k - i + 1) continue;
        ll timeReq = 0;
        timeReq += abs(xs - point[j].first) + abs(ys - point[j].second);
        timeReq += abs(point[j].first - point[i].first) + abs(point[j].second - point[i].second);
        if (j < k) timeReq += abs(point[i].first - point[k].first) + abs(point[i].second - point[k].second);
        if (timeReq <= t) ans = k - i + 1;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
