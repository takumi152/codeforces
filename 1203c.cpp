#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x: a) cin >> x;

  set<ll> numbers;
  for (auto &x: a) numbers.insert(x);
  vector<ll> divisors;
  ll smallest = *(numbers.begin());
  for (ll i = 1; i * i <= smallest; i++) {
    if (smallest % i == 0) {
      divisors.push_back(i);
      if (i * i != smallest) divisors.push_back(smallest / i);
    }
  }
  for (auto &x: numbers) {
    vector<ll> newDivisors;
    for (auto &y: divisors) {
      if (x % y == 0) newDivisors.push_back(y);
    }
    divisors = newDivisors;
  }

  cout << divisors.size() << endl;

  return 0;
}
