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
    int n, m;
    cin >> n >> m;

    string path;
    cin >> path;

    vll rSum(n+1, 0), cSum(m+1, 0);
    vector<vll> g(n+1, vll(m+1)), mark(n+1, vll(m+1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            rSum[i] += g[i][j];
            cSum[j] += g[i][j];
        }
    }

    int l = 1, r = 1;
    int64_t z;
    
    for (auto &d: path) {
        
        if (d == 'D') {
            z = rSum[l] * (-1);
            
            g[l][r] = z;
            rSum[l] = z + g[l][r];
            cSum[r] += z;
            
            l++;
            continue;
        } 

        
        z = cSum[r] * (-1);
            
        g[l][r] = z;
        cSum[r] = z + g[l][r];
        rSum[l] += z;
            
        r++;
        
        
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (i == n && j == m) {
                cout << cSum[m] * (-1) << " ";
                continue;
            }

            cout << g[i][j] << ' ';
        }
        cout << '\n';
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