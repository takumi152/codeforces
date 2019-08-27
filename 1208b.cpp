#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) cin >> x;

  unordered_map<int, int> count;
  for (auto &x: a) count[x]++;
  bool distinct = true;
  for (auto &x: count) {
    if (x.second >= 2) {
      distinct = false;
      break;
    }
  }
  if (distinct) {
    cout << 0 << endl;
    return 0;
  }
  int minimum = n;
  for (int i = 0; i < n; i++) {
    auto localCount = count;
    for (int j = i; j < n; j++) {
      localCount[a[j]]--;
      bool distinct = true;
      for (auto &x: localCount) {
        if (x.second >= 2) {
          distinct = false;
          break;
        }
      }
      if (distinct) {
        if (j - i + 1 < minimum) {
          minimum = j - i + 1;
        }
        break;
      }
      if (j - i + 1 >= minimum) break;
    }
  }

  cout << minimum << endl;

  return 0;
}
