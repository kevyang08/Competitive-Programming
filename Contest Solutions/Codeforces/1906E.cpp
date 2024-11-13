#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n, c[2001], a[1001], s[2001], ina[2001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    fill(a + 1, a + n + 1, INF);
    for (int i = 1; i <= 2 * n; i++) {
        cin >> c[i];
        if (c[i] > c[s[i - 1]]) s[i] = i;
        else s[i] = s[i - 1];

        // cout << i << " " << s[i] << "bruh\n";
    }
    for (int i = 1; i <= 2 * n; i++) {
        while (i < 2 * n && s[i + 1] == s[i]) ++i;
        for (int j = n; j >= i - s[i] + 1; j--) if (a[j - i + s[i] - 1] != INF && a[j] == INF) a[j] = i;
    }
    if (a[n] == INF) cout << "-1\n";
    else {
        for (int i = n; i > 0;) {
            // cout << i << " " << a[i] << " " << s[a[i]] << "bruh\n";

            ina[a[i]] = 1;
            --i;
            while (a[i + 1] > s[a[i + 1]]) { // bruh
                // cout << i << " bruh\n";
                a[i] = a[i + 1] - 1, ina[a[i]] = 1, --i;
            }
        }
        for (int i = 1; i <= 2 * n; i++) if (ina[i]) cout << c[i] << " ";
        cout << "\n";
        for (int i = 1; i <= 2 * n; i++) if (!ina[i]) cout << c[i] << " ";
        cout << "\n";
    }
    return 0;
}