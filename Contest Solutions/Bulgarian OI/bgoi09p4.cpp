#include <bits/stdc++.h>
using namespace std;

int n, h[1000000], j[1000000], ans[1000000];
vector<int> v;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> j[i];
    for (int i = n - 1; i >= 0; i--) {
        while (!v.empty() && v.back() <= h[i]) v.pop_back();
        v.push_back(h[i]);
        if (j[i] >= v.size()) ans[i] = -1;
        else ans[i] = v[v.size() - j[i] - 1];
    }
    cout << ans[0];
    for (int i = 1; i < n; i++) cout << " " << ans[i];
    cout << "\n";
    return 0;
}
