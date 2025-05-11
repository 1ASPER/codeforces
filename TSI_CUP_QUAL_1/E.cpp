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
    int n, m;
    cin >> n >> m;

    vi d(m);
    for (int &u: d) 
        cin >> u;


    vi val = {
        6, 
        2, 
        5, 
        5, 
        4, 
        5, 
        6, 
        3, 
        7, 
        6
    };

    vi dp(n+1, -100);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c = val[d[j]];
            
            if (c <= i && dp[i - c] >= 0) {
                dp[i] = max(
                    dp[i], 
                    dp[i-c] + 1
                );
            }
        }
    }

    // Log
    // for (int u: dp) {
    //     cout << u << " ";
    // }

    int mx_len = dp[n];

    vector<int> ans;
    int z = n;

    for (int p = 1; p <= mx_len; ++p) {
        for (int k = m - 1; k >= 0; --k) {

            int32_t c = val[d[k]];

            if (z >= c && dp[z - c] == dp[z] - 1) {
                ans.push_back(d[k]);
                z -= c;
                break;
            }
            
        }
    }

    for (int u: ans) {
        cout << u;
    }
    cout << "\n";
    // cout << dp[n] << "\n";

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

