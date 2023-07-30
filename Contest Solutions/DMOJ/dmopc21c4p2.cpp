#include <bits/stdc++.h>
using namespace std;

int n, j, cnt[5000001], c = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> j;
        cnt[j]++;
    }
    for (int i = 1; i <= 5000000; i++) {
        if (cnt[i] == 0) continue;
        c++;
        for (int j = 2 * i; j <= 5000000; j += i) cnt[j] = 0;
    }
    cout << c << "\n";
    return 0;
}
