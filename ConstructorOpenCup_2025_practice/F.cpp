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

    vector<int> a(n);
    for (int &i : a) cin >> i;

    auto check = [&](int z) {

        int last = a[0] - 1;


        for (int i = 1; i < n; ++i) {

            // options priority: [x-1, x, x+1]

            if (a[i] - last > z) {
                last = a[i] - 1;
            }
            else if (a[i] - last == z) {
                last = a[i];
            }
            else if (a[i] - last + 1 == z) {
                last = a[i] + 1;
            }
            else {
                return false;
            }
        }

        return true;
    };


    int l = 1, r = 1e9 + 7;
    while (l < r) {
        int m = (l + r) / 2;


        if (check(m)) {
            l = m + 1;
        }

        else {
            r = m;
        }
    }


    cout << l - 1 << "\n";


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

