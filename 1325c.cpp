#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<int> > edge(n);
  map<Pii, int> edgeID;
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    edge[a-1].push_back(b-1);
    edge[b-1].push_back(a-1);
    edgeID[Pii(a-1, b-1)] = i;
    edgeID[Pii(b-1, a-1)] = i;
  }

  vector<int> ans(n-1, -1);
  int next = 0;
  for (int i = 0; i < n; i++) {
    if ((int) edge[i].size() >= 3) {
      for (int j = 0; j < 3; j++) {
        ans[edgeID[Pii(i, edge[i][j])]] = next;
        next++;
      }
      break;
    }
  }

  for (int i = 0; i < n-1; i++) {
    if (ans[i] == -1) {
      ans[i] = next;
      next++;
    }
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
