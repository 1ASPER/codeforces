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
    int n, e, s;
    cin >> n >> e >> s;

    vi p(n+1);
    for (int i = 1; i < n; ++i) {
        cin >> p[i];
    }

    vll pref(n+1);
    pref[0] = 0;
    pref[1] = p[1];

    for (int i = 2; i < n + 1; ++i) {
        pref[i] = pref[i-1] + p[i];
    }

    ll ans = 0;

    vll dp(n+1, 0);
    dp[0] = 0;

    deque<pii> dq;


    // dp(i)? = dp(i-1-s) - pref(i-1)

    for (int i = 1; i < n + 1; ++i) {
        
        int lo = max(0, i - e);


        while (!dq.empty() && dq.front().first < lo) {
            dq.pop_front();
        }

        int z = i - 1;

        ll vl;

        if (z >= s) {
            vl = dp[z - s] - pref[z];
        }
        else {
            vl = 0 - pref[z];
        }

        while (!dq.empty() && vl >= dq.back().second) {
            dq.pop_back();
        }


        dq.emplace_back(z, vl);

        ll cur_mx = dq.empty()? -1e18: dq.front().second;
        dp[i] = max(dp[i-1], cur_mx + pref[i]);

    }


    cout << dp[n] << "\n";



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

