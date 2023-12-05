#include <bits/stdc++.h>
using namespace std;

int n, k, arr[2000][2000];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> k;
    int bruh = n * (n - 1);
    for (int i = 0; i < k; i++) {
        arr[i][i] = n * n - i;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            arr[i][j] = bruh--;
        }
    }
    for (int i = k; i < n; i++) {
        arr[i][0] = n * n - i;
        for (int j = 1; j < n; j++) arr[i][j] = bruh--;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cout << arr[i][j] << (j == n - 1 ? "\n" : " ");
    return 0;
}
