#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long int ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  vector<int> n(q);
  vector<vector<int> > a(q);
  for (int i = 0; i < q; i++) {
    cin >> n[i];
    a[i].assign(4 * n[i], 0);
    for (auto &x: a[i]) cin >> x;
  }

  vector<string> ans(q);
  for (int i = 0; i < q; i++) {
    map<int, int> counter;
    for (auto &x: a[i]) counter[x]++;
    for (auto &x: counter) {
      if (x.second % 2 == 1) {
        ans[i] = "NO";
        break;
      }
      x.second /= 2;
    }
    if (ans[i] != "NO") {
      auto left = counter.begin();
      auto right = counter.rbegin();
      int target = (*left).first * (*right).first;
      for (int j = 0; j < n[i]; j++) {
        if ((*left).first * (*right).first != target) {
          ans[i] = "NO";
          break;
        }
        (*left).second--;
        (*right).second--;
        if ((*left).second == 0) left++;
        if ((*right).second == 0) right++;
      }
    }
    if (ans[i] != "NO") {
      ans[i] = "YES";
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
