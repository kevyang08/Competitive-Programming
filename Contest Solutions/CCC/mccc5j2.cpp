#include <bits/stdc++.h>
using namespace std;

int u, t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> u >> t;
    cout << (u >= 20 && t >= 6 && t <= 9 && 24 + t - u >= 8 && 24 + t - u <= 10 ? "Healthy" : "Unhealthy") << "\n";
    return 0;
}
