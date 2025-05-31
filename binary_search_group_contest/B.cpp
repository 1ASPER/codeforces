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
    int c, m, x;
    cin >> c >> m >> x;

    auto check = [c, m, x](int t) {
        if (c >= t && m >= t) {
            int r = (c + m + x) - t * 3;
            if (r >= 0) {
                return true;
            }
        }
        return false;
    };

    int l = 0, r = max(c, m) + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;

        if (check(m)) {
            l = m;
        }
        else {
            r = m;
        }
    }


    cout << l << "\n";



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

