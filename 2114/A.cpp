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
    string s;
    cin >> s;

    int d = 0;
    for (int i = 0; i < sz(s); ++i) {
        d += (s[i] - '0') * pow(10, (3 - i));
    }

    for (int a = 0; a * a < d + 1; ++a) {
        for (int b = 0; b * b < d + 1; ++b) {
            if (pow((a + b), 2) == d) {
                cout << a << " " << b << "\n";
                return;
            }
        }
    }

    // cout << d << "\n";

    cout << "-1\n";

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

