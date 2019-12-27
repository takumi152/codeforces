#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 998244353;

ll modinv(ll x, ll m = mod) {
  ll b = m;
  ll u = 1;
  ll v = 0;
  ll tmp;
  while (b) {
    ll t = x / b;
    x -= t * b;
    tmp = x;
    x = b;
    b = tmp;
    u -= t * v;
    tmp = u;
    u = v;
    v = tmp;
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vector<ll> k(n);
  vector<vector<ll> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> k[i];
    a[i] = vector<ll>(k[i]);
    for (auto &x: a[i]) cin >> x;
  }

  unordered_map<ll, ll> appearance;
  for (int i = 0; i < n; i++) {
    for (auto &x: a[i]) appearance[x]++;
  }

  unordered_map<ll, pair<ll, ll> > chooseProbability;
  for (auto &x: appearance) chooseProbability[x.first] = make_pair(0L, 1L);
  for (int i = 0; i < n; i++) {
    for (auto &x: a[i]) {
      ll dividend = chooseProbability[x].second;
      chooseProbability[x].first = (chooseProbability[x].first * ((n * k[i]) % mod)) % mod;
      chooseProbability[x].second = (chooseProbability[x].second * ((n * k[i]) % mod)) % mod;
      chooseProbability[x].first = (chooseProbability[x].first + dividend) % mod;
    }
  }

  unordered_map<ll, pair<ll, ll> > matchProbability;
  for (auto &x: appearance) matchProbability[x.first] = chooseProbability[x.first];
  for (auto &x: appearance) {
    matchProbability[x.first].first = (matchProbability[x.first].first * appearance[x.first]) % mod;
    matchProbability[x.first].second = (matchProbability[x.first].second * n) % mod;
  }

  pair<ll, ll> totalProbability = make_pair(0L, 1L);
  for (auto &x: matchProbability) {
    ll dividend = (x.second.first * totalProbability.second) % mod;
    totalProbability.first = (totalProbability.first * x.second.second) % mod;
    totalProbability.second = (totalProbability.second * x.second.second) % mod;
    totalProbability.first = (totalProbability.first + dividend) % mod;
  }

  ll ans = (totalProbability.first * modinv(totalProbability.second)) % mod;

  cout << ans << endl;

  return 0;
}
