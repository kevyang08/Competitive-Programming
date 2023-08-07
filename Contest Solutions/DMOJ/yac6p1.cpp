#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (m) {
                cout << i << " " << j << "\n";
                m--;
            }
            else break;
        }
    }
    return 0;
}
