#include <bits/stdc++.h>
using namespace std;
 
int t, n, a;
long long arr[2][200001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        set<long long> s;
        bool thing = false;
        s.insert(0);
        for (int i = 1; i <= n; i++) {
            cin >> a;
            arr[i%2][i] = a + arr[i%2][i - 1];
            arr[(i + 1)%2][i] = arr[(i + 1)%2][i - 1];
            if (s.find(arr[1][i] - arr[0][i]) != s.end()) thing = true;
            s.insert(arr[1][i] - arr[0][i]);
        }
        cout << (thing ? "YES\n" : "NO\n");
    }
    return 0;
}
