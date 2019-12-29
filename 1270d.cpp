#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

vector<int> ask(vector<int> q) {
  cout << "? ";
  for (auto &x: q) cout << x << " ";
  cout << endl;
  vector<int> res(2);
  cin >> res[0];
  if (res[0] == -1) exit(0);
  cin >> res[1];
  return res;
}

void answer(int m) {
  cout << "! " << m << endl;
  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<vector<int> > res;
  for (int i = 0; i <= k; i++) {
    vector<int> query;
    for (int j = 0; j <= k; j++) {
      if (i == j) continue;
      query.push_back(j+1);
    }
    res.push_back(ask(query));
  }

  map<int, int> count;
  for (auto &x: res) {
    count[x[1]]++;
  }

  int ans = (*(count.rbegin())).second;

  answer(ans);

  return 0;
}
