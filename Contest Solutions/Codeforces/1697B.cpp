#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vector<long long> arr;
    arr.push_back(0);
    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++) arr[i] += arr[i - 1];
    while (q-- > 0) {
        int x, y;
        cin >> x >> y;
        cout << arr[n - x + y] - arr[n - x] << "\n";
    }
}
