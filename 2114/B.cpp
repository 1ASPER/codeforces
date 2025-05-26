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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int space = n - k;
    int32_t zero = 0, one = 0;
    for (char &u: s) {
        one += (u == '1');
        zero += (u == '0');
    }

    // Part 1
    while (k) {

        if (one >= zero) {
            one -= 2;
        }
        else {
            zero -= 2;
        }

        --k;
    }

    // Part 2
    if (space == 0 || zero == one) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";



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

