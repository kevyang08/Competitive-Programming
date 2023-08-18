#include <bits/stdc++.h>
using namespace std;

int n, a[1000001], arr[1000001];
long long ans = 0, c = 1;
deque<int> dq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]%2 == 0) dq.push_front(i);
        else dq.push_back(i);
    }
    dq.push_front(dq.back()); dq.pop_back();
    for (int i = 1; i <= n; i++) {
        arr[i] = dq.front(); dq.pop_front();
        if (a[arr[i]]%2) ans += a[arr[i]]/2;
        else ans += a[arr[i]]/2 - 1 + c%2;
        c += a[arr[i]];
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) cout << (i == 1 ? "" : " ") << arr[i];
    cout << "\n";
    return 0;
}
