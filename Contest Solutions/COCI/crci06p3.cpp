#include <bits/stdc++.h>
using namespace std;

int n, h, l, arr[500001], ans = 0x3f3f3f3f, c = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        cin >> l;
        if (i%2 == 1) arr[h - l + 1]++;
        else {
            arr[1]++;
            arr[l + 1]--;
        }
    }
    for (int i = 1; i <= h; i++) {
        arr[i] += arr[i - 1];
        if (arr[i] < ans) {
            ans = arr[i];
            c = 1;
        }
        else if (arr[i] == ans) c++;
    }
    cout << ans << " " << c << "\n";
}
