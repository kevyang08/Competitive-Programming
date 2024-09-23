#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll n, p;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("line_by_line_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        cin >> n >> p;
        cout << setprecision(6) << fixed << pow(p/100.0, (double)(n - 1)/n) * 100 - p << "\n";
    }
    return 0;
}