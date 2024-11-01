#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
first step takes m + 1 queries, where m is the number of nodes i with p[i] = 0
to get the second one, we have to go through all the nodes with p[i] = 0 and check whether or not it is a child
- should also take m queries
by now we should be at 2m + 1 queries, and we have to check n - 2 - (m + 2) nodes at one query each

total queries: 2m + 1 + n - 2 - (m + 2) = m + n - 3 <= 2n - 6 (since m <= n - 3)
*/

int t, n, p[10001], a[10001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int prev = 0, r, i = 2;
        // cout << "? 1 2" << endl;
        // cin >> r;
        // if (r) p[2] = 0;
        // else p[2] = 1, thing = 1;
        a[1] = 1;
        for (; i < n; i++) {
            cout << "? 1 " << i << endl;
            cin >> r;
            if (r) p[i] = 0, a[i] = i;
            else {
                prev = i - 1;
                p[i] = 1, a[i] = 1;
                break;
            }
        }
        ++i;
        // if (i < n) {
        //     for (; i < n; i++) {
        //         cout << "? " << i - 1 << " " << i << endl;
        //         cin >> r;
        //         if (r) break;
        //         else p[i] = i - 1, a[i] = a[i - 1];
        //     }
        // }
        for (int j = 2; i < n; i++) {
            while (j < p[i - 1]) ++j;
            cout << "? " << i - 1 << " " << i << endl;
            cin >> r;
            if (r) {
                while (j < i) {
                    while (j < i && a[j] == a[i - 1]) ++j;
                    cout << "? " << j << " " << i << endl;
                    cin >> r;
                    if (!r) {
                        p[i] = j, a[i] = a[j];
                        break;
                    }
                    ++j;
                }
            }
            else p[i] = i - 1, a[i] = a[i - 1];
        }
        cout << "!";
        for (int i = 1; i < n; i++) cout << " " << p[i];
        cout << endl;
    }
    return 0;
}