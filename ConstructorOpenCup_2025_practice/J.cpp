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
    string s;
    
    cin >> n >> s;


    vi pre(n + 1, 0), freq(26, 0);
    int d = 0;


    for (int i = 0; i < n; ++i) {
        if (freq[s[i] - 'a']++ == 0) d++;
        pre[i + 1] = d;
    }



    vi suf(n, 0);
    vi freq_suf(26, 0);

    d = 0;


    for (int i = n - 1; i >= 0; --i) {
        if (freq_suf[s[i] - 'a']++ == 0) 
            d++;

        suf[i] = d;
    }


    vector<vi> a_for_x(27), c_for_x(27);


    for (int i = 1; i <= n; ++i) {
        int x = pre[i];
        if (x <= 26) a_for_x[x].push_back(i);
    }


    for (int i = 0; i < n; ++i) {
        int x = suf[i];
        int c = n - i;
        if (x <= 26) c_for_x[x].push_back(c);
    }


    for (int x = 1; x <= 26; ++x) {
        if (a_for_x[x].empty() || c_for_x[x].empty()) 
            continue;

        sort(c_for_x[x].begin(), c_for_x[x].end());

        for (int a : a_for_x[x]) {
            int c_max = n - 1 - a;

            if (c_max < 1) 
                continue;

            auto& vec = c_for_x[x];
            auto it = upper_bound(vec.begin(), vec.end(), c_max);

            if (it == vec.begin()) 
                continue;

            for (auto c_it = it - 1; c_it >= vec.begin(); --c_it) {
                int c = *c_it;

                int ml = a;
                int mr = n - c - 1;

                if (ml > mr) 
                    continue;

                vi freq_mid(26, 0);

                int cnt = 0;
                bool ok = true;

                for (int i = ml; i <= mr; ++i) {
                    char ch = s[i];

                    if (freq_mid[ch - 'a']++ == 0) {
                        cnt++;
                        if (cnt > x) {
                            ok = false;
                            break;
                        }
                    }
                }

                if (ok && cnt == x) {
                    cout << "YES\n" << a << " " << (mr - ml + 1) << " " << c << "\n";
                    return;
                }

                // Early exit (opt)
                if (ok && cnt == x)
                    break;

            }
        }
    }

    cout << "NO\n";
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
