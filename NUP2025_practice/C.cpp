#include <bits/stdc++.h>
#define all(obj) obj.begin(), obj.end()
#define rall(obj) obj.rbegin(), obj.rend()
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

    vi a(n);
    for (int &u : a) {
        cin >> u;
    }

    sort(rall(a));
    vi ans;

    int cnt = 0, i = 0;
    while (i < n) {

        if (i < n && a[i-1] == a[i]) {
            cnt++;
            ans.push_back(a[i]);

            if (cnt == 2) {
                break;
            }   

            i += 2;
        }

        else {
            ++i;
        }

    }

    if (cnt == 2) {
        cout << ans[0] * ans[1] << "\n";
        return;
    }

    cout << "-1\n";



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

