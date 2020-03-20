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

  int t;
  cin >> t;
  vector<int> n(t);
  for (auto &x: n) cin >> x;

  vector<vector<int> > ans(t);
  for (int k = 0; k < t; k++) {
    if (n[k] == 1) ans[k] = vector<int>({-1});
    else {
      for (int i = 0; i < n[k]-2; i++) ans[k].push_back(7);
      ans[k].push_back(5);
      ans[k].push_back(7);
    }
  }

  for (auto &x: ans) {
    for (auto &y: x) cout << y;
    cout << endl;
  }

  return 0;
}
