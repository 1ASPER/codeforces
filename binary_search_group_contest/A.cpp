#include <bits/stdc++.h>
#define all(obj) obj.begin(), obj.end()
#define sz(obj) (int)obj.size()

using namespace std;
using ll = long long;
using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vpii = std::vector<pii>;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// https://codeforces.com/group/yeVhAfeK6s/contest/571840
void solve() {
    int n;
    cin >> n;

    vi a(n);
    for (int &u: a) cin >> u;
    sort(all(a));

    int q;
    cin >> q;

    while(q--) {

        int x;
        cin >> x;

        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;

            if (a[m] <= x) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        cout << l << "\n";

    }

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

