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
  vector<string> a(t);
  for (int i = 0; i < t; i++) {
    cin >> n[i];
    cin >> a[i];
  }

  vector<int> ans(t);
  for (int i = 0; i < t; i++) {
    bool illogicalAll = true;
    vector<bool> illogical(n[i]);
    for (int j = 0; j < n[i]; j++) {
      illogical[j] = (a[i][((j-1)+n[i])%n[i]] == a[i][(j+1)%n[i]] && a[i][((j-1)+n[i])%n[i]] == a[i][j]);
      if (!illogical[j]) illogicalAll = false;
    }

    if (illogicalAll) {
      ans[i] = (n[i] + 2) / 3;
      continue;
    }

    int offset = 0;
    for (int j = 0; j < n[i]; j++) {
      if (!illogical[j]) {
        offset = j;
        break;
      }
    }

    int illogicalLength = 0;
    for (int j = 0; j < n[i]; j++) {
      if (illogical[(j+offset)%n[i]]) illogicalLength++;
      else {
        ans[i] += (illogicalLength + 2) / 3;
        illogicalLength = 0;
      }
    }
    ans[i] += (illogicalLength + 2) / 3;
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
