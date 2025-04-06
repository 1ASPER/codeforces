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


bool valid() {

}

bool comp(int a, int b) {
    return a > b;
}


void solve() {

    string s;
    cin >> s;

    int n = sz(s);

    int c0 = count_if(all(s), [](char ch) { return ch == '0'; });
    int c1 = n / 2 + (n % 2) - c0;
    
    int clt = count_if(s.begin() + 1, s.end(), [](char ch) { return ch == '<'; });
    int cgt = (n / 2) - clt;
    
    int m = (n + 1) / 2, k = (n - 1) / 2;
    
    bool cnt = !(m & 1)? (c0 == c1): (abs(c0 - c1) == 1);

    if (!cnt) {
        cout << "NO\n";
        return;
    }
    
    vi starts = !(m & 1)? vi{0, 1}: (c0 > c1? vi{0}: vi{1});
    
    bool ok = any_of(all(starts), [&](int x) {
        int req_clt = (x == 0) ? (k + 1) / 2 : k / 2;
        int req_cgt = (x == 0) ? k / 2 : (k + 1) / 2;

        return (
                clt == req_clt && 
                cgt == req_cgt
                );

    });
    
    cout << (ok? "YES\n": "NO\n");
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

