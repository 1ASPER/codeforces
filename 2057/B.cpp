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

    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> counts;
    for (auto& [val, count] : freq) {
        counts.push_back(count);
    }
    
    sort(all(counts)); 

    int ans = sz(counts);
    for (int count: counts) {
        if (k >= count) {
            k -= count;
            ans--;
            continue;
        } 
        
        break;
        
    }
    
    cout << max(1, ans) << "\n";
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

