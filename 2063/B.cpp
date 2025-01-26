#include <bits/stdc++.h>
#define all(obj) obj.begin(), obj.end()
#define sz(obj) (int)obj.size()
#define range(v, x) upper_bound(all(v), x) - lower_bound(all(v), x)

using ll = long long;
using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vpii = std::vector<pii>;
using namespace std;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;


void solve() {

    int n, l, r;
    cin >> n >> l >> r;


    l--;
    r--; 


    vi a(n);
    for (int &x : a) 
        cin >> x;


    vi lo(a.begin(), a.begin() + r + 1);
    vi hi(a.begin() + l, a.end());


    sort(all(lo));
    sort(all(hi));



    // Calc min (r - l + 1)
    ll s_l = 0, s_h = 0;

    for (int i = 0; i < (r - l + 1); ++i) {
        s_l += lo[i];
        s_h += hi[i];
    }



    cout << min(s_l, s_h) << "\n";


}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
