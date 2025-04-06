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


set<ll> f = {1, 1};

void fibo() {
    ll a = 1, b = 1;

    while (b <= 1e17) {
        ll c = a + b;
        f.insert(c);
        a = b;
        b = c;
    }
}

void solve() {
    ll x;
    cin >> x;

    for (ll i = 1; i <= x / 2; ++i) {
        if (
            f.find(i) == f.end() &&
            f.find(x - i) == f.end()
        ) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int32_t main() {

    fibo();
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

