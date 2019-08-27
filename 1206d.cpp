// WIP

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>

using namespace std;

typedef long long int ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<bitset<64> > a(n);
  for (auto &x: a) cin >> x;

  bitset<64> visited;
  int ans = 1000000007;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 64; j++) {
      if (visited[j]) continue;
      if (a[i][j]) {
        visited.set(j);
        queue<pair<int, int> > que;
        que.
      }
    }
  }



  return 0;
}
