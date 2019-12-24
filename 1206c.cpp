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

  if (n % 2 == 0) {
    cout << "NO" << endl; // impossible
    return 0;
  }

  int now = 1;
  vector<int> ans(2 * n);
  for (int i = 0; i < n; i++) {
    ans[i] = now;
    if (i % 2 == 0) now += 3;
    else now += 1;
  }
  now = 2;
  for (int i = n; i < 2 * n; i++) {
    ans[i] = now;
    if (i % 2 == 0) now += 3;
    else now += 1;
  }

  cout << "YES" << endl;
  for (int i = 0; i < 2 * n; i++) {
    cout << ans[i];
    if (i < 2 * n - 1) cout << " ";
    else cout << endl;
  }

  return 0;
}
