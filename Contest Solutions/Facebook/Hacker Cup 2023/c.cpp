#include <bits/stdc++.h>
using namespace std;

int t, n, arr[600000];
int solve(int sum) {
    bool thing = false;
    int res1 = INT_MAX, res2 = INT_MAX;
    for (int i = 0, j = 2 * n - 2; i <= j; i++, j--) {
        if (i == j) res1 = sum - arr[i];
        else {
            if (arr[i] + arr[j] != sum) {
                if (thing) {
                    res1 = INT_MAX;
                    break;
                }
                else {
                    thing = true;
                    if (sum > arr[i]) {
                        res1 = sum - arr[i];
                        j++;
                    }
                    else {
                        res1 = INT_MAX;
                        break;
                    }
                }
            }
        }
    }
    thing = false;
    for (int i = 0, j = 2 * n - 2; i <= j; i++, j--) {
        if (i == j) res2 = sum - arr[i];
        else {
            if (arr[i] + arr[j] != sum) {
                if (thing) {
                    res2 = INT_MAX;
                    break;
                }
                else {
                    thing = true;
                    if (sum > arr[j]) {
                        res2 = sum - arr[j];
                        i--;
                    }
                    else {
                        res2 = INT_MAX;
                        break;
                    }
                }
            }
        }
    }
    return min(res1, res2);
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("two_apples_a_day_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        cin >> n;
        for (int i = 0; i < 2 * n - 1; i++) cin >> arr[i];
        sort(arr, arr + 2 * n - 1);
        int ans = (n > 1 ? min(solve(arr[0] + arr[2 * n - 2]), min(solve(arr[1] + arr[2 * n - 2]), solve(arr[0] + arr[2 * n - 3]))) : 1);
        cout << "Case #" << bruh << ": " << (ans == INT_MAX ? -1 : ans) << "\n";
    }
    return 0;
}
