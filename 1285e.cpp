#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
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
  vector<vector<Pii> > lr(t);
  for (int k = 0; k < t; k++) {
    cin >> n[k];
    lr[k] = vector<Pii>(n[k]);
    for (auto &x: lr[k]) cin >> x.first >> x.second;
  }

  vector<int> ans(t);
  for (int k = 0; k < t; k++) {
    sort(lr[k].begin(), lr[k].end());
    vector<int> loneness(n[k]);
    priority_queue<Pii, vector<Pii>, greater<Pii> > que;
    for (int i = 0; i < n[k]; i++) que.emplace(lr[k][i].first, i);
    unordered_set<int> seg;
    int c = 0;
    int lastc = 0;
    int lastlastc = 0;
    int lastp = -1000000007;
    int segCount = 0;
    while (!que.empty()) {
      auto now = que.top();
      que.pop();
      auto it = seg.find(now.second);
      if (it != seg.end()) {
        c--;
        seg.erase(it);
      }
      else {
        c++;
        if (now.first > lastp) {
          lastp = now.first;
          if (lastc == 0) segCount++;
          else if (lastlastc == 2 && lastc == 1) loneness[*(seg.begin())-1000000]++;
        }
        seg.insert(now.second + 1000000);
        que.emplace(lr[k][now.second].second, now.second + 1000000);
      }
      lastlastc = lastc;
      lastc = c;
    }
    int maxLoneness = 0;
    for (auto &x: loneness) {
      if (x > maxLoneness) maxLoneness = x;
    }
    ans[k] = min(n[k]-1, segCount + maxLoneness);
  }

  for (auto &x: ans) cout << x << endl;

  return 0;
}
