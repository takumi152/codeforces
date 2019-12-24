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

  int m;
  cin >> m;
  vector<ll> n(m), t(m), a(m), b(m);
  vector<vector<Pii> > p(m);
  for (int i = 0; i < m; i++) {
    cin >> n[i] >> t[i] >> a[i] >> b[i];
    p[i] = vector<Pii>(n[i]);
    for (auto &x: p[i]) cin >> x.second;
    for (auto &x: p[i]) cin >> x.first;
  }

  vector<int> ans(m);
  for (int k = 0; k < m; k++) {
    sort(p[k].begin(), p[k].end());
    ll e = 0, h = 0;
    for (int i = 0; i < n[k]; i++) {
      if (p[k][i].second == 0) e++;
      else h++;
    }
    p[k].emplace_back(t[k]+1, 0); // sentinel
    int best = 0;
    ll elapsed = 0;
    if (elapsed < p[k][0].first) {
      if (elapsed + e * a[k] >= p[k][0].first) {
        int left = 0;
        int right = e;
        while (left < right) {
          int center = (left + right + 1) / 2;
          ll lt = elapsed + center * a[k];
          if (lt < p[k][0].first) left = center;
          else right = center - 1;
        }
        if (left > best) best = left;
      }
      else {
        int left = 0;
        int right = h;
        while (left < right) {
          int center = (left + right + 1) / 2;
          ll lt = elapsed + e * a[k] + center * b[k];
          if (lt < p[k][0].first) left = center;
          else right = center - 1;
        }
        if (e + left > best) best = e + left;
      }
    }
    for (int i = 0; i < n[k]; i++) {
      if (p[k][i].second == 0) {
        elapsed += a[k];
        e--;
      }
      else {
        elapsed += b[k];
        h--;
      }
      if (elapsed < p[k][i+1].first) {
        if (elapsed + e * a[k] >= p[k][i+1].first) {
          int left = 0;
          int right = e;
          while (left < right) {
            int center = (left + right + 1) / 2;
            ll lt = elapsed + center * a[k];
            if (lt < p[k][i+1].first) left = center;
            else right = center - 1;
          }
          if (i + left + 1 > best) best = i + left + 1;
        }
        else {
          int left = 0;
          int right = h;
          while (left < right) {
            int center = (left + right + 1) / 2;
            ll lt = elapsed + e * a[k] + center * b[k];
            if (lt < p[k][i+1].first) left = center;
            else right = center - 1;
          }
          if (i + e + left + 1 > best) best = i + e + left + 1;
        }
      }
    }
    ans[k] = best;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
