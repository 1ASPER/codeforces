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
    int n;
    cin >> n;

    int64_t s = 0;
    vi a(n);


    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;

        s += u;

        a[i] = u;
    }

    int g = s / n;

    vector<tuple<int, int, int>> ops;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if (i != j && a[i] + a[j] == 2 * n) {

                if (a[i] > a[j]) {
                    ops.push_back({i, j, a[i]-a[j]});
                }
                else {
                    ops.push_back({j, i, a[j]-a[i]});
                }

                a[i] = g;
                a[j] = g;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if (i != j && a[i] > g && a[j] < g) {

                ops.push_back({i, j, a[i]-a[j]});
                
                a[i] -= a[i]-a[j];
                a[j] += a[i]-a[j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }

    cout << endl;
    cout << sz(ops) << "\n";

    for (const auto& op : ops) {
        cout << get<0>(op) << " " << get<1>(op) << " " << get<2>(op) << "\n";
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

