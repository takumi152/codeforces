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

const ll mod = 998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<ll> p(n);
  for (auto &x: p) cin >> x;

  ll start = 0;
  while (p[start] <= n - k) start++;
  ll value = p[start];
  ll partCount = 1;
  ll nowCount = 1;
  for (int i = start+1; i < n; i++) {
    if (p[i] <= n - k) nowCount++;
    else {
      value += p[i];
      partCount = (partCount * nowCount) % mod;
      nowCount = 1;
    }
  }

  cout << value << " " << partCount << endl;

  return 0;
}
