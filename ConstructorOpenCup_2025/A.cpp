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
    
    int32_t a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    
    
    int32_t lo = max({a1, b1, c1}), hi = min({a2, b2, c2});  
    
    if (lo <= hi) {
        cout << lo << "\n";
        return;
    } 
    
    cout << "0\n";
    
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    
    return 0;
}