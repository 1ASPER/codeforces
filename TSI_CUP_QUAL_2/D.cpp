#include <bits/stdc++.h>
#define all(obj) obj.begin(), obj.end()
#define sz(obj) (int)obj.size()
#define int long long

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


int calc(int a, int k) {
    return a * k + (k * (k - 1)) / 2;
}


void print(int B, int C) {
    if (B > C) {
        cout << "1 ";
    }
    else if (B < C) {
        cout << "2 ";
    }
    else {
        cout << "0 ";
    }

    cout << abs(B - C) << "\n";
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;

    // Operation
    // a -> b & b+=1
    // b -> a & a+=1

    // PART 1
    // Reach (a == b)
    // delta = |a - b|

    // PART 2
    // Calculate the winner
    // When (a == b)
    // y = a + (a + 1) + (a + 2) + ... + (a + k)
    // y = a * (k + 1) + [k * (k + 1)] / 2


    int B = 0, C = 0;
    int mA = min(a, b), mB = max(a, b); 
    int dx = abs(a - b);

    int x = min(k * 2, dx);
    int y = (k * 2) - x;



    // if (dx < k) {

    //     B += calc(
    //         min(a, b), 
    //         (k + 1) >> 1
    //     );

    //     C += calc(
    //         min(a, b),
    //         k >> 1
    //     );

    //     // LOG
    //     cout << "No a==b case:\n";
    //     cout << B << " " << C <<"\n";
    //     cout <<"\n";

    //     print(B, C);
    //     return;
    // }

    int B_t = mB * ((x + 1) >> 1), C_t = mB * (x >> 1);
    int B_s = k - ((x + 1) >> 1), C_s = k - (x >> 1);

    // B += calc(
    //     min(a, b),
    //     (dx + 1) >> 1
    // );

    // C += calc(
    //     min(a, b),
    //     dx >> 1
    // );

    // cout << "BEFORE a==b\n" << B << " " << C <<"\n"; 



    B = B_t + calc(
        mA + x + ((x % 2 + 1) >> 1),
        B_s
    );

    C = C_t + calc(
        mA + x + (((1 - x % 2) + 1) >> 1),
        C_s
    );


    

    // if (!(dx & 1)) {
    //     B += calc(
    //         max(a, b),
    //         ( ((k+1)>>1) - (dx+1) ) >> 1
    //     );
    //     C += calc(
    //         max(a, b),
    //         (k >> 1) - (dx >> 1)
    //     );

    //     // LOG
    //     cout << "AFTER a==b\n" << B << " " << C <<"\n"; 

    //     print(B, C);
    // }

    // else {
    //     B += calc(
    //         max(a, b),
    //         (k >> 1) - (dx + 1) >> 1
    //     );
    //     C += calc(
    //         max(a, b),
    //         ((k + 1) >> 1) - (dx >> 1)
    //     );

    //     // LOG
    //     cout << "AFTER a==b\n" << B << " " << C <<"\n"; 

    //     print(B, C);
    // }



    print(B, C);
    


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

