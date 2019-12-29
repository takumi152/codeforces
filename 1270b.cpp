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

  int t;
  cin >> t;
  vector<int> n(t);
  vector<vector<int> > a(t);
  for (int k = 0; k < t; k++) {
    cin >> n[k];
    a[k] = vector<int>(n[k]);
    for (auto &x: a[k]) cin >> x;
  }

  vector<string> ans(t);
  vector<Pii> range(t);
  for (int k = 0; k < t; k++) {
    int smallest = 0;
    int largest = 0;
    int good = false;
    for (int i = 0; i < n[k]; i++) {
      if (a[k][i] < a[k][smallest] + (i - smallest)) {
        smallest = i;
      }
      else if (a[k][i] > a[k][smallest] + (i - smallest)) {
        largest = i;
        good = true;
        break;
      }
    }
    if (good) {
      ans[k] = "YES";
      range[k] = make_pair(smallest+1, largest+1);
      continue;
    }
    reverse(a[k].begin(), a[k].end());
    smallest = 0;
    for (int i = 0; i < n[k]; i++) {
      if (a[k][i] < a[k][smallest] + (i - smallest)) {
        smallest = i;
      }
      else if (a[k][i] > a[k][smallest] + (i - smallest)) {
        largest = i;
        good = true;
        break;
      }
    }
    if (good) {
      ans[k] = "YES";
      range[k] = make_pair(n[k]-largest, n[k]-smallest);
    }
    else {
      ans[k] = "NO";
    }
  }

  for (int k = 0; k < t; k++) {
    cout << ans[k] << endl;
    if (ans[k] == "YES") cout << range[k].first << " " << range[k].second << endl;
  }

  return 0;
}
