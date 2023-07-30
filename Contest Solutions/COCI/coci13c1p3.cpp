#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, arr[55][55], c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            unordered_map<int, int> cnt;
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < j; l++) {
                    int temp = arr[i][j] - arr[k][j] - arr[i][l] + arr[k][l];
                    if (cnt.find(temp) == cnt.end()) cnt.insert({temp, 0});
                    cnt[temp] = cnt.at(temp) + 1;
                }
            }
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    if (cnt.find(arr[k + 1][l + 1] - arr[i][l + 1] - arr[k + 1][j] + arr[i][j]) != cnt.end()) c += cnt.at(arr[k + 1][l + 1] - arr[i][l + 1] - arr[k + 1][j] + arr[i][j]);
                }
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            unordered_map<int, int> cnt;
            for (int k = 0; k < i; k++) {
                for (int l = j; l < n; l++) {
                    int temp = arr[i][l + 1] - arr[i][j] - arr[k][l + 1] + arr[k][j];
                    if (cnt.find(temp) == cnt.end()) cnt.insert({temp, 0});
                    cnt[temp] = cnt.at(temp) + 1;
                }
            }
            for (int k = i; k < n; k++) {
                for (int l = 0; l < j; l++) {
                    if (cnt.find(arr[k + 1][j] - arr[k + 1][l] - arr[i][j] + arr[i][l]) != cnt.end()) c += cnt.at(arr[k + 1][j] - arr[k + 1][l] - arr[i][j] + arr[i][l]);
                }
            }
        }
    }
    cout << c << "\n";
    return 0;
}
