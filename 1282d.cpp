#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long int ll;
typedef pair<int, int> Pii;

const ll mod = 1000000007;

int ask(vector<char> q) {
  for (auto &x: q) cout << x;
  cout << endl;
  int res;
  cin >> res;
  if (res == -1 || res == 0) exit(0);
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<char> s;
  s.push_back('a');
  int res = ask(s);
  if (res == 300) {
    s.clear();
    for (int i = 0; i < res; i++) s.push_back('b');
    ask(s);
    return 0;
  }
  for (int i = 0; i < res; i++) s.push_back('a');
  int lastRes = res;
  res = ask(s);
  if (res > lastRes) {
    s.clear();
    for (int i = 0; i < lastRes; i++) s.push_back('b');
    ask(s);
    return 0;
  }
  int n = s.size();
  for (int i = 0; i < n; i++) {
    lastRes = res;
    s[i] = 'b';
    res = ask(s);
    if (res >= lastRes) s[i] = 'a';
  }

  return 0;
}
