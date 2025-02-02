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
    int n, w;
    cin >> n >> w;

    vi a(n), b(n);
    for (int &u: a) 
        cin >> u;

    for (int &u: b)
        cin >> u;


    int max_b = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] + b[i] > w && a[i+1] + b[i+1] > w) {
            if (b[i+1] > max_b) {
                max_b = b[i+1];
            }
        }
    }

    cout << max_b << "\n";
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

