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


struct S
{
    int32_t size;
    int32_t val;
};



void solve() {
    int v1, v2, n;
    cin >> v1 >> v2 >> n;

    vector<S> a(n);

    
    for (int i = 0; i < n; ++i) {
        cin >> a[i].size >> a[i].val;
    }


    vector<vi> dp(105, vi(105, 0));
    // for (int i = 0; i <= v1; ++i) {
    //     for (int j = 0; j <= v2; ++j) {
    //         dp[i][j] = ;
    //     }
    // }


    for (S& b: a) 
    {
        int sz = b.size, vl = b.val;

        for (int i = v1; i >= 0; --i) {
            for (int j = v2; j >= 0; --j) {

                if (i + sz <= v1) {
                    dp[i+sz][j] = max(dp[i+sz][j], dp[i][j] + vl);
                }
                if (j + sz <= v2) {
                    dp[i][j+sz] = max(dp[i][j+sz], dp[i][j] + vl);
                }

            }
        }
    }



    ll ans = 0;
    for (int i = 0; i <= v1; ++i) {
        for (int j = 0; j <= v2; ++j) {
            ans = max(ans, dp[i][j] * 1ll);
        }
    }



    cout << ans << "\n";

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

