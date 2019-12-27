// WIP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k, l;
  cin >> n >> k >> l;
  string s;
  cin >> s;

  vector<int> low(n+1), high(n+1);
  for (int i = 0; i < n; i++) {
    low[i+1] = low[i];
    high[i+1] = high[i];
    if ('a' <= s[i] && s[i] <= 'z') low[i+1]++;
    else high[i+1]++;
  }

  return 0;
}
