#include <bits/stdc++.h>
#define all(obj) obj.begin(), obj.end()
#define sz(obj) (int)obj.size()

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
    
    int n, m;
    cin >> n >> m;

    vi a(n), b(m);
    for (int &u: a) cin >> u;
    for (int &u: b) cin >> u;

    auto check = [&](int r) -> bool {
        int j = 0;

        for (int i = 0; i < n; ++i) {
            while (
                j + 1 < m                             && 
                abs(b[j + 1] - a[i]) <= abs(b[j] - a[i])
            ) {
                ++j;
            }

            if (abs(b[j] - a[i]) > r) {
                return false;
            }
        }   

        return true;
    };


    int lo = -1, hi = 1e9;
    while (lo + 1 < hi) {
        int r = (lo + hi) / 2;

        if (check(r)) {
            hi = m;
        }
        else {
            lo = m;
        }
    }


    cout << hi << "\n";
    


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

