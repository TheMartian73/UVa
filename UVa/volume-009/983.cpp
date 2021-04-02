/*
 * TheMartian0x48 
 * 983
 */

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> v(1005, vi(1005));
  bool first = true;
  v[0].assign(1005, 0);
  int n, m;
  while (cin >> n >> m) {
    if (first) first =false;
    else { cout << "\n"; }
    ll res = 0;
    
    for (int i = 1; i <= n; i++) {
      v[i][0] = 0;
      for (int j = 1; j <= n; j++) {
        cin >> v[i][j];
      }
    }
    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        v[i][j] += v[i - 1][j];
        v[i][j] += v[i][j - 1];
        v[i][j] -= v[i - 1][j - 1];
        if (i >= m && j >= m) {
          ll sum = v[i][j];
          sum -= v[i - m][j];
          sum -= v[i][j - m];
          sum += v[i - m][j - m];
          res += sum;
          cout << sum << "\n";
        }
      }
    }
    cout << res << "\n";
  }
}
