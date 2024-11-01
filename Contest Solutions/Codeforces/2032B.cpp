#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int t, n, k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k == 1 && n != 1 || k == n && n != 1) cout << "-1\n";
        else if (k == 1 && n == 1) {
            cout << "1\n1\n";
        }
        else if (k%2 == 0) {
            cout << "3\n";
            cout << "1 " << k << " " << k + 1 << "\n";
        }
        else {
            cout << "3\n";
            cout << "1 " << k - 1 << " " << k + 2 << "\n";
        }
    }
    return 0;
}

/*
always possible for even
for odd other than 1 and n, 
*/