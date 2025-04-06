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


bool comp(int a, int b) {
    return a > b;
}


void solve() {
    
    int n, A, B;
    cin >> n >> A >> B;
    
    vector<int> d(n);
    
    for (int32_t &u: d) 
        cin >> u;
        
    int a_only = 0, b_only = 0, ab = 0;
    
    
    for (int x: d) {
        
        if (x > A && x > B) {
            continue;
        }
            
        if (x <= A) {
            
            if (x <= B) {
                ++ab;
            } 

            else {
                a_only++;
            }
            
            
            continue;
        } 
        
        if (x <= B) {
            ++b_only;
        }

        
    }
    
    
    int32_t opt1 = min(a_only + ab, b_only + ab), opt2 = (a_only + b_only + ab) / 2;


    cout << min(opt1, opt2) * 2 << "\n";



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

