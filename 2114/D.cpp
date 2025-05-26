#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> monsters(n);
        vector<ll> x, y;
        for (int i = 0; i < n; ++i) {
            cin >> monsters[i].first >> monsters[i].second;
            x.push_back(monsters[i].first);
            y.push_back(monsters[i].second);
        }
        
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        ll min_x = x[0];
        ll max_x = x.back();
        ll min_y = y[0];
        ll max_y = y.back();
        
        auto cnt_min_x = upper_bound(x.begin(), x.end(), min_x) - x.begin();
        auto cnt_max_x = x.end() - lower_bound(x.begin(), x.end(), max_x);
        auto cnt_min_y = upper_bound(y.begin(), y.end(), min_y) - y.begin();
        auto cnt_max_y = y.end() - lower_bound(y.begin(), y.end(), max_y);
        
        ll original_area = (max_x - min_x + 1) * (max_y - min_y + 1);
        ll min_area = original_area;
        
        for (auto& [xi, yi] : monsters) {
            ll new_min_x = min_x;
            ll new_max_x = max_x;
            if (xi == min_x && cnt_min_x == 1) new_min_x = x[1];
            if (xi == max_x && cnt_max_x == 1) new_max_x = x[x.size() - 2];
            if (xi == max_x && cnt_max_x == 1) new_max_x = x[x.size() - 2];
            
            ll new_min_y = min_y;
            if (yi == min_y && cnt_min_y == 1) new_min_y = y[1];
            ll new_max_y = max_y;
            if (yi == max_y && cnt_max_y == 1) new_max_y = y[y.size() - 2];
            
            ll dx = new_max_x - new_min_x + 1;
            ll dy = new_max_y - new_min_y + 1;
            ll area_candidate = dx * dy;
            
            if (area_candidate == n - 1) {
                ll option1 = (dx + 1) * dy;
                ll option2 = dx * (dy + 1);
                area_candidate = min(option1, option2);
            }
            
            if (area_candidate < min_area) {
                min_area = area_candidate;
            }
        }
        
        cout << min(original_area, min_area) << "\n";
    }
    
    return 0;
}