#include <bits/stdc++.h>
using namespace std;

int n, a, b, cnta[101], cntb[101];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cnta[a]++;
        cntb[b]++;
        int mx = 0, idx = 100, c = cnta[100];
        for (int i = 1; i < 101; i++) {
            int temp = cntb[i];
            while (temp) {
                while (c == 0) c = cnta[--idx];
                if (temp > c) {
                    temp -= c;
                    c = 0;
                }
                else {
                    c -= temp;
                    temp = 0;
                }
                mx = max(mx, i + idx);
            }
        }
        cout << mx << "\n";
    }
}
