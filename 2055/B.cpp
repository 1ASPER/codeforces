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
    
    vi a(n), b(n), proceed(n);
    for (int &i : a) cin >> i;

    ll need = 0, extra = 0;

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        proceed[i] = b[i] - a[i];
        
        
        if (proceed[i] > 0)
            need += proceed[i];
        else
            extra += proceed[i];
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if ((proceed[i] > 0 && a[i] - need + 2 * proceed[i] < b[i]) || (proceed[i] <= 0 && a[i] - need < b[i])) 
            ok = false;
    }
    
    cout << (ok ? "YES" : "NO") << "\n";
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

