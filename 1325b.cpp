#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>

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
  vector<vector<int> > a(t);
  for (int i = 0; i < t; i++) {
    cin >> n[i];
    a[i] = vector<int>(n[i]);
    for (int j = 0; j < n[i]; j++) cin >> a[i][j];
  }

  vector<int> ans(t);
  for (int k = 0; k < t; k++) {
    unordered_set<int> appeared;
    for (int i = 0; i < n[k]; i++) appeared.insert(a[k][i]);
    ans[k] = appeared.size();
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
