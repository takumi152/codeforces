// WA

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

template <class T>
struct segtree {
  int n;
  vector<T> data;

  segtree(const int s) {
    init(s);
  }

  segtree(const int s, const T u) {
    init(s);
    for (int i = 0; i < s; i++) {
      data[i+n-1] = u;
    }
    for (int i = n-2; i >= 0; i--) {
      data[i] = min(data[i*2+1], data[i*2+2]);
    }
  }

  segtree(const vector<T> &v) {
    int s = v.size();
    init(s);
    for (int i = 0; i < s; i++) {
      data[i+n-1] = v[i];
    }
    for (int i = n-2; i >= 0; i--) {
      data[i] = min(data[i*2+1], data[i*2+2]);
    }
  }

  void init(const int s) {
    n = 1;
    while (n < s) n <<= 1;
    data = vector<T>(2*n-1, 0x7fffffff);
  }

  void update(int x, T v) {
    int p = x + n - 1;

    // update bottom
    data[p] = v;

    // update rest
    while (p > 0) {
      p = (p - 1) >> 1;
      data[p] = min(data[p*2+1], data[p*2+2]);
    }
  }

  T query(int l, int r, int p = 0, int a = 0, int b = -1) {
    if (b < 0) b = n; // init
    if (r <= a || b <= l) return 0x7fffffff; // out of range

    if (l <= a && b <= r) return data[p];// fully covered

    int vl = query(l, r, p*2+1, a, (a + b) / 2); // left
    int vr = query(l, r, p*2+2, (a + b) / 2, b); // right
    return min(vl, vr);
  }

  T mindex(int l, int r, int p = 0, int a = 0, int b = -1) {
    if (b < 0) b = n; // init
    if (r <= a || b <= l) return -1; // out of range

    if (l <= a && b <= r) { // fully covered
      if (p >= n-1)                       return p - (n - 1);
      else if (data[p*2+1] < data[p*2+2]) return mindex(l, r, p*2+1, a, (a + b) / 2);
      else                                return mindex(l, r, p*2+2, (a + b) / 2, b);
    }

    int vl = mindex(l, r, p*2+1, a, (a + b) / 2); // left
    int vr = mindex(l, r, p*2+2, (a + b) / 2, b); // right
    if (vl == -1 && vr == -1) return -1;
    else if (vl == -1) return vr;
    else if (vr == -1) return vl;
    else if (data[vl+n-1] < data[vr+n-1]) return vl;
    else return vr;
  }
};

struct unionfind {
  vector<int> group;

  unionfind(int n) {
    group = vector<int>(n);
    for (int i = 0; i < n; i++) group[i] = i;
  }

  int root(int x) {
    if (group[x] == x) return x;
    return group[x] = root(group[x]);
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    group[rx] = ry;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> p(n), q(n);
  for (auto &x: p) cin >> x;
  for (auto &x: q) cin >> x;

  for (int i = 0; i < n; i++) p[i] = -p[i];

  segtree<int> st(p);
  unionfind uf(n);

  vector<int> ans(n);
  ans[0] = n;
  for (int i = 0; i < n-1; i++) {
    int target = q[i];
    if (q[i] < n) {
      uf.unite(q[i]-1, q[i]);
      target = uf.root(q[i]-1);
    }
    int mindex = st.mindex(0, target);
    st.update(mindex, 0);
    ans[i+1] = -st.query(0, n);
    //for (auto &x: st.data) cerr << x << " ";
    //cerr << endl;
    //cerr << target << endl;
  }

  for (auto &x: ans) cout << x << " ";
  cout << endl;

  return 0;
}
