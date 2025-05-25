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


int64_t bfs(int s, vi &a, vector<vpii> &g) {

    int n = sz(g);
    vector<bool> used(n, false);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    int64_t bal = 0;

    used[s] = true;
    bal += a[s];

    for (auto [to, w]: g[s]) {
        pq.push({w, to});
    }


    while (!pq.empty()) {

        auto [req, u] = pq.top();
        if (req > bal) 
            break;

        pq.pop();

        if (used[u]) {
            continue;
        }

        used[u] = true;
        bal += a[u];

        for (auto [v, w2]: g[u]) {

            if (!used[v]) {
                pq.push({w2, v});
            }
        }
    }

    return bal;
}

void solve() {

    int n, m, s;
    cin >> n >> m >> s;

    --s;

    vi a(n);
    for (int &u: a) cin >> u;

    vector<vpii> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }


    cout << bfs(s, a, g) << "\n";
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

