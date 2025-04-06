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

int q(int type, int i) {
    cout << type << " " << i << "\n";
    cout.flush();

    string s;
    int x;

    cin >> s >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    vi a(n);

    int my_type = 2;
    int x;


    for (int i = 0; i < n; ++i) {

        x = q(my_type, i + 1);

        if (x == 0 && my_type == 2) {
            my_type = 1;
            x = q(my_type, i + 1);
        }
        
        a[i] = x;

    }

    cout << "0 ";
    for (int &u: a)
        cout << u << " ";

    cout << "\n";
    cout.flush();

    string res;
    cin >> res;

    if (res == "ERROR") 
        exit(0);

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

