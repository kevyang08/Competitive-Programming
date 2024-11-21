#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int avg, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> avg >> c;
    if (80 * (c + 1) - avg * c <= 100) cout << max(80 * (c + 1) - avg * c, 0) << "\n";
    else cout << "-1\n";
    return 0;
}