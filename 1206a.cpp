#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x: a) cin >> x;
  int m;
  cin >> m;
  vector<int> b(m);
  for (auto &x: b) cin >> x;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans1 = a[n-1];
  int ans2 = b[m-1];

  cout << ans1 << " " << ans2 << endl;

  return 0;
}
