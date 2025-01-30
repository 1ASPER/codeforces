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

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_alpha(char c) {
    return c >= 'a' && c <= 'z';
}

void solve() {
    string s;
    cin >> s;

    bool flag = true;
    bool is_O_before = false;
    bool is_first_digit = true;

    for (char c: s) {

        if ( (is_digit(c) && is_O_before) || (c == '0' && is_first_digit) ) {
            flag = false;
            break;
        }

        // For next iter
        if (c == 'O') {
            is_O_before = true;
        } 
        else if (is_digit(c)) {
            is_first_digit = false;
            is_O_before = false;
        }
        else {
            is_O_before = false;
        }

    }


    cout << ( (flag && s[sz(s) - 1] != 'O')? "YES": "NO") << "\n";

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

