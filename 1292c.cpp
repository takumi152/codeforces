// WIP

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

  int n;
  cin >> n;
  vector<vector<int> > edge(n);
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    edge[a-1].push_back(b-1);
    edge[b-1].push_back(a-1);
  }

  for (int i = 0; i < n; i++) {
    if (edge[i].size() == 1) {
      vector<bool> visited(n);
      vector<int> d(n);
      queue<Pii> que;
      que.emplace(i, 0);
      while (!que.empty()) {
        auto now = que.front();
        que.pop();
        if (visited[now.first]) continue;
        visited[now.first] = true;
        d[now.first] = now.second;
        for (auto &x: edge[now.first]) {
          if (visited[x]) continue;
          que.emplace(x, now.second + 1);
        }
      }
      for (int j = 0; j < n; j++) {
        if (edge[j].size() == 1 && d[j] > 0) {

        }
      }
    }
  }

  return 0;
}
