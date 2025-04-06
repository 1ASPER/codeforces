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
    ll n;
    cin >> n;

    if (n == 1) {
        cout << "1 1\n1\n";
        return;
    }

    vll v;
    ll s = 0, cur = 2;

    while (s + cur <= n) {
        v.push_back(cur);

        s += cur;
        cur++;
    }

    ll dist = n - s;
    unsigned long long prod = 1;


    if (dist) {
        if (dist >= cur) {
            v.push_back(dist);
        }

        else {

            int id = sz(v) - 1;
            while (dist > 0) {
                ++v[id];
                --dist;

                id = (id - 1 + sz(v)) % sz(v);
            }

        }
    }



    for (auto &u: v) {
        prod *= u;
    }

    if (1) {
        cout << prod << " " << sz(v) << "\n";
        for (auto &u: v) cout << u << " ";
        cout << "\n";
    }


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

