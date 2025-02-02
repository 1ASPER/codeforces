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
    int n;
    cin >> n;

    vi p(n);

    for (auto &u: p) {
        cin >> u;
    }

    vi ord = p;
    sort(all(ord));

    int m;
    cin >> m;

    vi s(m);
    for (auto &u: s) {
        cin >> u;
    }


    for (int i = 0; i < m; ++i) {
        cout << upper_bound(all(ord), p[s[i]-1]) - ord.begin() << " ";
    }

    cout << "\n";
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

