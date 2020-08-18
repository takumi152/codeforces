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

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x: a) cin >> x;

  ll total = 0;
  for (int i = 0; i < n; i++) total += a[i];

  vector<ll> ans(n);
  for (int i = 0; i < n; i++) ans[i] = i;

  ll sum = ((n - 1) * n) / 2;
  ll flatinc = (total - sum) / n;
  for (int i = 0; i < n; i++) ans[i] += flatinc;
  sum += flatinc * n;

  for (int i = 0; i < n; i++) {
    if (sum >= total) break;
    ans[i]++;
    sum++;
  }

  for (auto &x: ans) cout << x << " ";
  cout << endl;

  return 0;
}
