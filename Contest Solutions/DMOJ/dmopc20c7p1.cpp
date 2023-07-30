#include <bits/stdc++.h>
using namespace std;

int n, arr[1000000], idx[1000000], ans = 0;
bool cmp(int a, int b) {return arr[a] < arr[b];}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
        idx[i] = i;
    }
    sort(idx, idx + 2 * n, cmp);
    for (int i = 0; i < n; i++) if (arr[idx[i]] != arr[idx[i + n]]) ans++;
    cout << ans << "\n";
    for (int i = 0; i < n; i++) cout << idx[i] + 1 << " " << idx[i + n] + 1 << "\n";
}
