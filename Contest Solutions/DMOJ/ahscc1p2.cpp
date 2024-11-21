#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n == 1 && m == 1) cout << "1\n1\n";
    else if (n == 1) {
        cout << "2\n";
        for (int i = 1; i <= m; i++) cout << 1 + i%2 << (i == m ? "\n" : " ");
    }
    else if (m == 1) {
        cout << "2\n";
        for (int i = 1; i <= n; i++) cout << 1 + i%2 << "\n";
    }
    else {
        cout << "4\n";
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) cout << (i%2 * 2) + j%2 + 1 << (j == m ? "\n" : " ");
        }
    }
    return 0;
}