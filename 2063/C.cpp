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


bool comp(int a, int b) {
    return a > b;
}


void solve() {
    
    int n;
    cin >> n;

    vi dg(n + 1, 0);
    vector<vi> g(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

        ++dg[u]; ++dg[v];
    }


    vi vt(n);
    for (int i = 1; i <= n; ++i) {
        vt[i - 1] = i;
    }


    sort(all(vt), comp);


    int k = min(n, 200);
    vi top_k(vt.begin(), vt.begin() + k);



    vi id(n + 1, -1);
    for (int i = 0; i < k; ++i) {
        id[top_k[i]] = i;
    }


    vector<unordered_set<int>> adj(k);
    for (int i = 0; i < k; ++i) {

        int u = top_k[i];

        for (int v: g[u]) {
            if (id[v] != -1) {
                adj[i].insert(v);
            }
        }
    }



    int mx = 0;
    // calc 
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {

            int u = top_k[i];
            int v = top_k[j];
            int sm = dg[u] + dg[v];

            if (adj[i].count(v)) {
                sm -= 1;
            }


            mx = max(mx, sm);
        }
    }

    cout << mx - 1 << "\n";


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

