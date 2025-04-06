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

    int32_t cnt = 0;

    for (int &u: a) {
        cin >> u;
        cnt += u;
    }

    vpii g;
    for (int i = 0; i < n; ) {

        if (a[i] == 1) {
            int start = i;
            while (i < n && a[i] == 1) {
                i++;
            }
            g.emplace_back(start, i - 1);
            continue;
        } 

        ++i;
        
    }


    if (g.empty()) {
        cout << "YES\n";
        return;
    }



    bool ok = true;

    int ptr = -1;

    for (auto &[s, e] : g) {


        bool lo = (s > 0) && (a[s - 1] == 0);
        bool hi = (e < n - 1) && (a[e + 1] == 0);

        if (!lo && !hi) {
            ok = false;
            break;
        }



        int ns, ne;

        if (lo && hi) {
            int ptrL_s = s - 1;
            int ptrL_e = e - 1;
            int ptrR_s = s + 1;
            int ptrR_e = e + 1;

            if (ptrL_s > ptr) {
                ns = ptrL_s;
                ne = ptrL_e;
            } 
            else if (ptrR_s > ptr) {
                ns = ptrR_s;
                ne = ptrR_e;
            } 
            else {
                ok = false;
                break;
            }

        } 

        else if (lo) {

            ns = s - 1;
            ne = e - 1;
            if (ns <= ptr) {
                ok = false;
                break;
            }

        } 
        else { 

            ns = s + 1;
            ne = e + 1;

            if (ns <= ptr) {
                ok = false;
                break;
            }

        }



        ptr = ne;


    }



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

