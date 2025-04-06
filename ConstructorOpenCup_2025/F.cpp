// One accept a day keeps the doctor away 
//      | ________________ |
//      ||          ____  ||
//      ||   /\    |      ||
//      ||  /__\   |      ||
//      || /    \  |____  ||
//      ||________________||
//      |__________________|
//      \###################\
//       \###################\
//        \        ____       \
//         \_______\___\_______\

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

    vi a(n);
    vll ans(n+1, 0);
    vector<vi> v;

    
    for (int32_t &u: a) 
        cin >> u;
    
    
    int32_t st = 0;

    for (int i = 1; i < n; ++i) {

        if (a[i] < a[i-1]) {
            v.emplace_back(a.begin()+st, a.begin()+i);
            st = i;
        }
    }

    v.emplace_back(a.begin()+st, a.end());
    
    for (vi &u : v) {

        int L = u.size();
        ll s = 0;

        for (int i = L - 1; i >= 0; --i) {
            s += u[i];
            int z = L - i;

            if (z > n) {
                continue;
            }
            
            ans[z] = max(ans[z], s);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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

