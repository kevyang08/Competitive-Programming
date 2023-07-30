#include <bits/stdc++.h>
using namespace std;

int n, a;
long long ans = 0;
stack<int> s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> a;
    s.push(a);
    for (int i = 1; i < n; i++) {
        long long c = 0;
        cin >> a;
        while (!s.empty() && s.top() <= a) {
            s.pop();
            c++;
        }
        if (c == 0) ans += s.top();
        else ans += a;
        s.push(a);
    }
    cout << ans << "\n";
}
