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
  vector<int> x(t);
  for (auto &y: x) cin >> y;

  vector<Pii> ans(t);
  for (int i = 0; i < t; i++) ans[i] = Pii(1, x[i]-1);

  for (auto &y: ans) cout << y.first << " " << y.second << endl;

  return 0;
}
