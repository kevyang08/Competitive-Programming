#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t;
ll b, c, d;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> b >> c >> d;
        ll a = 0;
        // int bruh = 0;
        for (int i = 62; i >= 0; i--) {
            ll j = (1LL << i);
            if (j & d) {
                if (!(j & b) && (j & c)) {
                    a = -1;
                    break;
                }
                else if (!(j & b) && !(j & c)) a += j;
            }
            else {
                if ((j & b) && !(j & c)) {
                    a = -1;
                    break;
                }
                else if ((j & b) && (j & c)) a += j;
            }
        }
        // if (bruh) a = -1;
        cout << a << "\n";
    }
    return 0;
}