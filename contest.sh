#!/bin/bash

# Check for 2 arguments
if [ $# -ne 2 ]; then
    echo "Usage: $0 <contest_id> <problem_number>"
    exit 1
fi

contest_id=$1
problem_number=$2

# Template C++ code
template_code='#include <bits/stdc++.h>
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
'

# Create contest directory
mkdir -p "$contest_id"
cd "$contest_id" || exit

# Create problem files
for ((i=0; i<problem_number; i++)); do
    file_name="$(printf "%b.cpp" "$(echo $((65 + i)) | awk '{printf "%c", $1}')" )"
    echo "$template_code" > "$file_name"
done


# Log
echo "$problem_number problems created for contest $contest_id"

# Open the directory in Visual Studio Code
code .
