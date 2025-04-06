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

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;


    // There are 4 cases:
    //
    // 1. All points in the first quadrant or third quadrant
    //    x1 > 0, y1 > 0, x2 > 0, y2 > 0 -----> 0
    //    x1 < 0, y1 < 0, x2 < 0, y2 < 0 -----> 0
    //
    // 2. Diagonal neighbours
    //    x1 > 0, y1 > 0, x2 < 0, y2 < 0 -----> max(abs(x1) + abs(y2), abs(y1) + abs(x2))
    //    x1 < 0, y1 < 0, x2 > 0, y2 > 0 -----> max(abs(x1) + abs(y2), abs(y1) + abs(x2))
    //
    // 3. Non-diagonal neighbours
    //    x1 > 0, y1 < 0, x2 < 0, y2 < 0 -----> abs(y1 - y2)
    //    x1 < 0, y1 > 0, x2 > 0, y2 > 0 -----> abs(y1 - y2)
    //    x1 > 0, y1 < 0, x2 > 0, y2 > 0 -----> abs(x1 - x2)
    //    x1 < 0, y1 > 0, x2 < 0, y2 < 0 -----> abs(x1 - x2)
    //    ....
    //
    // 4. On the axis
    //    x1 = 0, x2 = 0 -----> abs(y1 - y2)
    //    y1 = 0, y2 = 0 -----> abs(x1 - x2)



    // In the one box 
    if ( 
        (x1 > 0 && y1 > 0 && x2 > 0 && y2 > 0) ||
        (x1 < 0 && y1 < 0 && x2 < 0 && y2 < 0) ||
        (x1 > 0 && y1 < 0 && x2 > 0 && y2 < 0) ||
        (x1 < 0 && y1 > 0 && x2 < 0 && y2 > 0) ) {

        cout << 0 << "\n";
    }

    // In the same line

    else if (x1 == 0 && x2 == 0) {
        cout << abs(y1 - y2) << "\n";
    } 
    
    else if (y1 == 0 && y2 == 0) {
        cout << abs(x1 - x2) << "\n";
    } 


    // Dioganal neighbours
    else if (
        (x1 >= 0 && y1 >= 0 && x2 <= 0 && y2 <= 0) ||
        (x1 <= 0 && y1 <= 0 && x2 >= 0 && y2 >= 0) ){
            cout << max( {abs(x1) + abs(y2), abs(y1) + abs(x2), abs(y1 - y2), abs(x1 - x2) });
    }

    else if (
        (x1 <= 0 && y1 >= 0 && x2 >= 0 && y2 <= 0) ||
        (x1 >= 0 && y1 <= 0 && x2 <= 0 && y2 >= 0) ){
            cout << max( {abs(x1) + abs(y2), abs(y1) + abs(x2), abs(y1 - y2), abs(x1 - x2) });
    }




    // Non-diagonal neighbours

    // In one line
    else if (x1 == x2 || y1 == y2) {
        cout << 1 << "\n";
    } 

    // In diff line
    else if (x1 > 0 && y1 < 0 && x2 < 0 && y2 < 0) {
        cout << abs(y1 - y2) << "\n";
    }

    else if (x1 < 0 && y1 > 0 && x2 > 0 && y2 > 0) {
        cout << abs(y1 - y2) << "\n";
    }

    else if (x1 > 0 && y1 < 0 && x2 > 0 && y2 > 0) {
        cout << abs(x1 - x2) << "\n";
    }

    else if (x1 < 0 && y1 > 0 && x2 < 0 && y2 < 0) {
        cout << abs(x1 - x2) << "\n";
    }

    else if (x1 > 0 && y1 > 0 && x2 < 0 && y2 > 0) {
        cout << abs(y1 - y2) << "\n";
    }

    else if (x1 < 0 && y1 < 0 && x2 > 0 && y2 < 0) {
        cout << abs(y1 - y2) << "\n";
    }

    else if (x1 > 0 && y1 > 0 && x2 > 0 && y2 < 0) {
        cout << abs(x1 - x2) << "\n";
    }

    else if (x1 < 0 && y1 < 0 && x2 < 0 && y2 > 0) {
        cout << abs(x1 - x2) << "\n";
    }

    
    else {
        cout << "IDK" << "\n";
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

