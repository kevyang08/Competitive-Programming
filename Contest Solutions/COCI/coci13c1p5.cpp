#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin >> n;
    long long mx = 0, arr[2000001];
    fill(arr, arr + 2000001, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x]++;
    }
    for (int i = 1; i < 2000001; i++) {
        for (int j = 2 * i; j < 2000001; j += i) arr[i] += arr[j];
        if (arr[i] > 1) mx = max(mx, arr[i] * i);
    }
    cout << mx << "\n";
    return 0;
}
