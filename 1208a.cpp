#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long int ll;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  vector<int> a(T), b(T), n(T);
  for (int i = 0; i < T; i++) {
    cin >> a[i] >> b[i] >> n[i];
  }

  vector<int> ans(T);
  for (int i = 0; i < T; i++) {
    set<int> found;
    vector<int> sequence;
    int x1 = a[i];
    int x2 = b[i];
    int x3 = x1 ^ x2;
    found.insert(x1);
    found.insert(x2);
    found.insert(x3);
    sequence.push_back(x1);
    sequence.push_back(x2);
    sequence.push_back(x3);
    do {
      x1 = x2;
      x2 = x3;
      x3 = x1 ^ x2;
      found.insert(x3);
      sequence.push_back(x3);
    } while (found.find(x3) == found.end());
    int length = found.size();
    if (length < 3) length = 3;
    ans[i] = sequence[n[i] % length];
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
