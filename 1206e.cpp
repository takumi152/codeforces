// WIP

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstdlib>

using namespace std;

typedef long long int ll;

vector<vector<bool> > ans;
vector<vector<bool> > known;

bool ask(int x1, int y1, int x2, int y2) {
  int response;
  cout << "? " << x1+1 << " " << y1+1 << " " << x2+1 << " " << y2+1 << flush;
  cin >> response;
  if (response == -1) exit(0); // failure
  cout << "!" << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      if (ans[j][i]) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      if (known[j][i]) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }
  return (response == 1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int remaining = n * n;

  ans = vector<vector<bool> > (n, vector<bool>(n, false));
  known = vector<vector<bool> > (n, vector<bool>(n, false));

  ans[0][0] = true;
  known[0][0] = true;
  // vertical
  for (int i = 0; i < n - 2; i += 2) {
    bool res = ask(0, i, 0, i+2);
    if (res) ans[0][i+2] = ans[0][i];
    else ans[0][i+2] = !ans[0][i];
    known[0][i+2] = true;
  }
  // horizonal
  for (int i = 0; i < n - 2; i += 2) {
    bool res = ask(i, 0, i+2, 0);
    if (res) ans[i+2][0] = ans[i][0];
    else ans[i+2][0] = !ans[i][0];
    known[i+2][0] = true;
  }
  // diagonal
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j += 2) {
      bool res;
      if (i % 2 == 0) {
        res = ask(i, j, i+1, j+1);
        if (res) ans[i+1][j+1] = ans[i][j];
        else ans[i+1][j+1] = !ans[i][j];
        known[i+1][j+1] = true;
      }
      else {
        res = ask(i, j+1, i+1, j+2);
        if (res) ans[i+1][j+2] = ans[i][j+1];
        else ans[i+1][j+2] = !ans[i][j+1];
        known[i+1][j+2] = true;
      }
    }
  }

  // check 3x3 of top-left
  bool res = ask(0, 0, 1, 2);
  if (res) {
    ans[1][2] = ans[0][0];
    known[1][2] = true;
  }
  else {
    if (ans[0][2] == ans[1][1]) {
    }
    else {
      ans[1][2] = !ans[0][0];
      known[1][2] = true;
    }
  }
  if (known[1][2]) {
    res = ask(1, 0, 1, 2);
    if (res) ans[1][0] = ans[1][2];
    else ans[1][0] = !ans[1][2];
    known[1][0] = true;
    res = ask(1, 0, 2, 1);
    if (res) ans[2][1] = ans[1][0];
    else ans[2][1] = !ans[1][0];
    known[2][1] = true;
    res = ask(0, 1, 2, 1);
    if (res) ans[0][1] = ans[2][1];
    else ans[0][1] = !ans[2][1];
    known[0][1] = true;
  }
  else {
    res = ask(0, 1, 2, 2);
    if (res) {
      ans[0][1] = ans[2][2];
      ans[1][2] = ans[1][1];
    }
    else {

    }
    if (known[1][2]) {
      res = ask(0, 1, 2, 1);
      if (res) ans[2][1] = ans[0][1];
      else ans[2][1] = !ans[0][1];
      known[2][1] = true;
      res = ask(1, 0, 2, 1);
      if (res) ans[1][0] = ans[2][1];
      else ans[1][0] = !ans[2][1];
      known[1][0] = true;
      res = ask(1, 0, 1, 2);
      if (res) ans[1][2] = ans[1][0];
      else ans[1][2] = !ans[1][0];
      known[1][2] = true;
    }
  }

  // vertical
  for (int i = 1; i < n - 2; i += 2) {
    bool res = ask(0, i, 0, i+2);
    if (res) ans[0][i+2] = ans[0][i];
    else ans[0][i+2] = !ans[0][i];
    known[0][i+2] = true;
  }
  // horizonal
  for (int i = 1; i < n - 2; i += 2) {
    bool res = ask(i, 0, i+2, 0);
    if (res) ans[i+2][0] = ans[i][0];
    else ans[i+2][0] = !ans[i][0];
    known[i+2][0] = true;
  }
  // diagonal
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j += 2) {
      bool res;
      if (i % 2 == 1) {
        res = ask(i, j, i+1, j+1);
        if (res) ans[i+1][j+1] = ans[i][j];
        else ans[i+1][j+1] = !ans[i][j];
        known[i+1][j+1] = true;
      }
      else {
        res = ask(i, j+1, i+1, j+2);
        if (res) ans[i+1][j+2] = ans[i][j+1];
        else ans[i+1][j+2] = !ans[i][j+1];
        known[i+1][j+2] = true;
      }
    }
  }

  cout << "!" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i][j]) cout << 1;
      else cout << 0;
    }
    cout << endl;
  }

  return 0;
}
