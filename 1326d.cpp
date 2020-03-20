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

const ll mod = 998244353;

vector<int> manacher(string &t) {
  string s;
  for (auto &x: t) {
    s.push_back('$'); // dummy char
    s.push_back(x);
  }
  s.push_back('$'); // dummy char
  int n = s.length();

  vector<int> rad(n);
  for (int i = 0, j = 0; i < n;) {
    while (i - j >= 0 && i + j < n) {
      if (s[i-j] == s[i+j]) j++;
      else break;
    }
    rad[i] = j;

    int k = 1;
    while (i - k >= 0) {
      if (rad[i-k] < rad[i] - k) {
        rad[i+k] = rad[i-k];
        k++;
      }
      else break;
    }

    i += k;
    j = max(j - k, 0);
  }

  return rad;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  vector<string> s(t);
  for (auto &x: s) cin >> x;

  vector<string> ans(t);
  for (int k = 0; k < t; k++) {
    int n = s[k].length();
    int p1 = 0;
    int p2 = n-1;
    while (p1 < p2) {
      if (s[k][p1] == s[k][p2]) {
        p1++;
        p2--;
      }
      else break;
    }
    if (p1 >= p2) {
      ans[k] = s[k];
      continue;
    }
    string c = s[k].substr(p1, p2 - p1 + 1);
    vector<int> rad = manacher(c);
    int longest = 0;
    int idx = 0;
    for (int i = 0; i < (int) rad.size(); i++) {
      if ((i - rad[i] < 0 || i + rad[i] >= (int) rad.size()) && rad[i] > longest) {
        longest = rad[i];
        idx = i;
      }
    }
    if (idx % 2 == 1) {
      ans[k] = s[k].substr(0, p1) + c.substr(idx / 2 - longest / 2 + 1, longest - 1) + s[k].substr(p2 + 1, n - p2 - 1);
    }
    else {
      ans[k] = s[k].substr(0, p1) + c.substr(idx / 2 - longest / 2, longest - 1) + s[k].substr(p2 + 1, n - p2 - 1);
    }
  }

  for (auto &x: ans) cout << x << '\n';

  return 0;
}
