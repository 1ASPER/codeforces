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
    ll l, r;
    cin >> l >> r;
    
    ll cnt = 0, ptr = 30;
    
    for (; ptr >= 0; ptr--) {
        if ((l & (1 << ptr)) == (r & (1 << ptr))) {
            if (l & (1 << ptr)) { 
                cnt += (1 << ptr);
                }
            continue;
        } 
        break;
    }
    
    ll a, b, c;
    if (r > cnt + (1 << ptr)) {
        a = cnt + (1 << ptr) - 1;
        b = cnt + (1 << ptr);
        c = cnt + (1 << ptr) + 1;
    } 
    else {
        a = cnt + (1 << ptr) - 2;
        b = cnt + (1 << ptr) - 1;
        c = cnt + (1 << ptr);
    }
    
    cout << a << " " << b << " " << c << "\n";
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
