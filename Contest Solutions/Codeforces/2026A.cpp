#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << "0 0 " << min(x, y) << " " << min(x, y) << "\n";
        cout << "0 " << min(x, y) << " " << min(x, y) << " 0\n";
    }
    return 0;
}