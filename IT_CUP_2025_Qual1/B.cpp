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
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(all(a));

        // vi odds, evens;

        // for (int i = 0; i < n; ++i) {
        //     if (a[i] % 2 == 0) {
        //         evens.push_back(a[i]);
        //         continue;
        //     } 
            
        //     odds.push_back(a[i]);
        // }

        // if (abs(sz(odds) - sz(evens)) > 1) {
        //     cout << "-1\n";
        //     return;
        // }

        vi p;
        int lo = 0, hi =  n - 1;

        bool flag = true;
        while (lo <= hi) {

            if (flag) {
                p.push_back(a[hi]);
                --hi;
            } 

            else {
                p.push_back(a[lo]);
                ++lo;
            }

            flag = flag ? false : true;

        }


        bool ok = true;
        for (int i = 2; i < n; ++i) {
            vi temp(p.begin(), p.begin()+i);
            sort(all(temp));

            int64_t x, y;
            x = temp[i/2 - 1];
            y = temp[i/2];

            if ((x + y) & 1){
                ok = false;
                break;
            }

        }


        if (ok) {
            cout << "-1\n";
            return;
        }


        for (int i = 0; i < n; ++i) {
            cout << p[i] << " ";
        }
        cout << "\n";

        
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

