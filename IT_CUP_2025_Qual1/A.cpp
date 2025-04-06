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

// PASSED
// 3 3 180
// *..
// .*.
// ..*

// PASSED
// 3 2 0
// ..*
// *..

// PASSED
// 3 2 90
// ..*
// *..


void solve() {
    
    int N, M, A;
    cin >> N >> M >> A;

    // 450 -> 90
    // 360 -> 0
    // -90 -> 270
    // - 450 -> 270
    A = (A % 360 + 360) % 360;


    vector<string> g(M);
    for (int i = 0; i < M; ++i) {
        cin >> g[i];
    }

    vector<string> ans;

    if (A == 0) {
        cout << N << " " << M << "\n";

        for (int i = 0; i < M; ++i) {
            cout << g[i] << "\n";
        }

        return;
    } 
    

    if (A == 90) {

        ans.resize(N, string(M, '.'));

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans[j][M - 1 - i] = g[i][j];
            }
        }

        cout << M << " " << N << "\n";

        for (int i = 0; i < N; ++i) {
             cout << ans[i] << "\n";
        }

        return;
    } 
    
    if (A == 180) {

        ans = g;
        reverse(all(ans));
        for (int i = 0; i < M; ++i) reverse(all(ans[i]));

        cout << N << " " << M << "\n";

        for (int i = 0; i < M; ++i) {
            cout << ans[i] << "\n";
        }

        return;
    } 
    
    else {
        ans.resize(N, string(M, '.'));

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                ans[N-1-j][i] = g[i][j];
            }
        }

        cout << M << " " << N << "\n";

        for (int i = 0; i < N; ++i) { 
            cout << ans[i] << "\n";
        }
    }
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

