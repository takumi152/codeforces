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
  vector<int> a(n);
  for (auto &x: a) cin >> x;

  sort(a.begin(), a.end());
  vector<int> w;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (a[i] == 1) {
        w.push_back(a[i]);
      }
      else {
        w.push_back(a[i]-1);
      }
      ans++;
    }
    else {
      if (w[ans-1] < a[i]-1) {
        w.push_back(a[i]-1);
        ans++;
      }
      else if (w[ans-1] < a[i]) {
        w.push_back(a[i]);
        ans++;
      }
      else if (w[ans-1] < a[i]+1) {
        w.push_back(a[i]+1);
        ans++;
      }
    }
  }

  cout << w.size() << endl;

  return 0;
}
