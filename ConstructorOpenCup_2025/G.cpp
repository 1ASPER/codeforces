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
#define sz(obj) (int)(obj).size()
#define range(v, x) (upper_bound(all(v), x) - lower_bound(all(v), x))
#define int long long

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


int calc_max_sum(int R1, int L1, int U1, int D1, int R2, int L2, int U2, int D2, int k) {

    int mx = 0;

    // Q1: x >=0, y >=0, x + y =k
    vi y_cand = {0, k, U1, D2, k - R1, k - L2};
    for (int y: y_cand) {
        if (y < 0 || y > k) 
            continue;

        int x = k - y;
        if (x < 0) 
            continue;

        int sum_ac = min(R1, x) + min(L2, x);
        int sum_bd = min(U1, y) + min(D2, y);
        
        mx = max(mx, sum_ac + sum_bd);
    }

    // Q4: x >=0, y <=0, x - y =k
    vi x_cand4 = {0, k, R1, L2, k - D1, k - U2};
    for (int x: x_cand4) {
        if (x < 0 || x > k) 
            continue;

        int y = x - k;
        if (y > 0) 
            continue;

        int sum_ac = min(R1, x) + min(L2, x);
        int sum_bd = min(D1, (k - x)) + min(U2, (k - x));

        mx = max(mx, sum_ac + sum_bd);
    }

    // Q2: x <=0, y >=0, -x + y =k
    vi y_cand2 = {k, 0, U1, D2, R2, k - L1};
    for (int y: y_cand2) {
        if (y < 0 || y > k) 
            continue;

        int x = -(k - y);

        if (x > 0) 
            continue;

        int sum_ac = min(L1, (k - y)) + min(R2, (k - y));
        int sum_bd = min(U1, y) + min(D2, y);

        mx = max(mx, sum_ac + sum_bd);
    }

    // Q3: x <=0, y <=0, -x - y =k
    vi x_cand3 = {0, -k, -L1, -R2, -(k - D1), -(k - U2)};
    for (int x: x_cand3) {
        if (x > 0)  
            continue;

        int y = -k - x;

        if (y > 0) 
            continue;

        int sum_ac = min(L1, -x) + min(R2, -x);
        int sum_bd = min(D1, -y) + min(U2, -y);

        mx = max(mx, sum_ac + sum_bd);
    }

    return mx;
}

void solve() {
    string s;
    cin >> s;

    int n = sz(s);
    int k = n / 2;

    string s1 = s.substr(0, k);
    string s2 = s.substr(k, k);

    int R1 = count(all(s1), 'R');
    int L1 = count(all(s1), 'L');
    int U1 = count(all(s1), 'U');
    int D1 = count(all(s1), 'D');

    int R2 = count(all(s2), 'R');
    int L2 = count(all(s2), 'L');
    int U2 = count(all(s2), 'U');
    int D2 = count(all(s2), 'D');


    cout << 2 * k - calc_max_sum(R1, L1, U1, D1, R2, L2, U2, D2, k) << "\n";


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
