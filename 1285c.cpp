#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

unordered_map<ll, int> primeFactorize(ll x) {
  unordered_map<ll, int> factor;
  ll a = 2;
  while (a * a <= x) {
    if (x % a == 0) {
      factor[a]++;
      x /= a;
    }
    else {
      a++;
    }
  }
  factor[x]++;
  return factor;
}

ll gcd(ll a, ll b) {
  while (b > 0) {
    ll rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll x;
  cin >> x;

  auto primeFactor = primeFactorize(x);
  vector<ll> mulFactor;
  for (auto &x: primeFactor) {
    ll a = 1;
    for (int i = 0; i < x.second; i++) a *= x.first;
    mulFactor.push_back(a);
  }
  ll minimum = (ll) 9e18;
  pair<ll, ll> minPair;
  for (int i = 0; i < (1 << primeFactor.size()); i++) {
    int p = i;
    ll a = 1;
    for (auto &x: mulFactor) {
      if (p & 1) a *= x;
      p >>= 1;
    }
    ll b = x / a;
    if (max(a, b) < minimum) {
      minimum = max(a, b);
      minPair = make_pair(a, b);
    }
  }

  cout << minPair.first << " " << minPair.second << endl;

  return 0;
}
