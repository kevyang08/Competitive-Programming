#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t, arr[500], p[100000];
    cin >> t;
    for (int i = 0; i < 500; i++) arr[i] = i * i;
    while (t--) {
        int n;
        cin >> n;
        bool used[n];
        fill(used, used + n, false);
        bool thing = true;
        for (int i = n - 1; i >= 0; i--) {
            if (i > 0) {
                int l = 0, r = 500, x = (int)pow((int)sqrt(i + n - 1), 2);
                while (l < r) {
                    int m = (l + r)/2;
                    if (x == arr[m]) {
                        l = m;
                        break;
                    }
                    else if (x > arr[m]) l = m + 1;
                    else r = m - 1;
                }
                while (used[abs(arr[l] - i)]) {
                    l--;
                    if (l < 0) {
                        thing = false;
                        break;
                    }
                }
                p[i] = abs(arr[l] - i);
                used[abs(arr[l] - i)] = true;
            }
            else {
                int j = 0;
                while (used[arr[j]]) {
                    j++;
                    if (arr[j] >= n) {
                        thing = false;
                        break;
                    }
                }
                p[0] = arr[j];
            }
        }
        if (!thing) cout << "-1\n";
        else {
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << p[i];
            }
            cout << "\n";
        }
    }
    return 0;
}
