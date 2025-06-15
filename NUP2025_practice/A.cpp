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

    string s;
    cin >> s;

    int32_t V = 0, P = 0, V_wins = 0, P_wins = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'V') {
            ++V;
        }
        else {
            ++P;
        }

        if (V == 5) {
            V_wins++;
            V = 0;
            P = 0;
        }
        else if (P == 5) {
            P_wins++;
            P = 0;
            V = 0;
        }
    }

    cout << P_wins << " " << V_wins << "\n";
    cout << P << " " << V << "\n";


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

