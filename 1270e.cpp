// WIP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<ll, ll> > xy(n);
  for (auto &x: xy) cin >> x.first >> x.second;

  unordered_map<ll, vector<Pii> > euclid;
  vector<vector<ll> > distMat(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      ll d = abs(xy[i].first - xy[j].first) * abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second) * abs(xy[i].second - xy[j].second);
      euclid[d].emplace_back(i, j);
      distMat[i][j] = d;
      distMat[j][i] = d;
    }
  }
  set<ll> euclidDupe;
  for (auto &x: euclid) {
    if (x.second().size() >= 2) {
      euclidTemp.insert(x.first);
    }
  }
  if (euclidDupe.empty()) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }

  for (auto &d: euclidDupe) {
    vector<vector<int> > edge(n);
    for (auto &x: euclid[d]) {
      edge[x.first].push_back(x.second);
      edge[x.second].push_back(x.first);
    }
    vector<bool> black(n);
    vector<bool> white(n);
    for (int i = 0; i < n; i++) {

    }
  }


  return 0;
}
