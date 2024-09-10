#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, b;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int free = 0, tot = 0, curr = 0, bruh = 0;
        for (int i = 1; i <= n; i++) {
            cin >> b;
            if (b == 2) {
                if (!curr) continue;
                if (bruh) --curr, ++free;
                free += curr/2;
                bruh = curr%2;
                curr = 0;
            }
            else {
                ++curr;
                if (!tot) --curr;
                if (free) --free;
                else ++tot;
            }
            // cout << free << " " << tot << " " << curr << " " << bruh << " wtf\n";
        }
        cout << tot << "\n";
    }
    return 0;
}