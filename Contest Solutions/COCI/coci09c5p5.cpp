#include <bits/stdc++.h>
using namespace std;

long long arr[1000000];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k, x, q, l, r;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        arr[0]++;
        arr[x]++;
    }
    for (int i = n - 1; i > 0; i--) 
        for (int j = 2 * i; j < n; j += i)
            arr[j] += arr[i];
    for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << (l == 0 ? arr[r] : arr[r] - arr[l - 1]) << "\n";
    }
}
