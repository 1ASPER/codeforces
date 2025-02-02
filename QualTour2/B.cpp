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


const int MAX = 2000000000;

void solve() {
    int n;
    cin >> n;


    int min_w = 1, max_w = MAX;


    int x; char c;
    for (int i = 0; i < n; ++i) {
        // min_w -> max
        // max_x -> min

        cin >> x >> c;

        // Ok
        if (c == 'G') {
            min_w = max(min_w, x);
            max_w = min(max_w, MAX);
        }

        // Ok
        else if (c == 'Y') {
            min_w = max(min_w, (x + 1) / 2);
            max_w = min(max_w, x - 1);
        }

        // Ok (18: 6-8)
        else if (c == 'R') {
            min_w = max(min_w, (x + 2) / 3);
            max_w = min(max_w, (x - 1) / 2);
        }

        // ok

        else {
            min_w = max(min_w, 1);
            max_w = min(max_w, (x - 1) / 3);
        }

    }


    if (min_w > max_w) {
        cout << "-1\n";
    } 

    else {
        cout << min_w << " " << max_w << "\n";
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

