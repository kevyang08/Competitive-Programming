#include <bits/stdc++.h>
using namespace std;

int arr[1 << 10], k;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> k;
    for (int i = 0; i < (1 << k) - 1; i++) cin >> arr[i];
    queue<pair<int, int>> q;
    q.push({0, (1 << k) - 2});
    while (!q.empty()) {
        pair p = q.front(); q.pop();
        int m = (p.first + p.second)/2;
        cout << arr[m] << (p.second == (1 << k) - 2 ? "\n" : " ");
        if (p.first == p.second) continue;
        q.push({p.first, m - 1});
        q.push({m + 1, p.second});
    }
}
