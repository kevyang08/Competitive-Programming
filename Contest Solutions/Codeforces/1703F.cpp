#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        long long c = 0;
        int n;
        cin >> n;
        vector<pair<int, int>> arr;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (a < i) {
                int l = 0, r = arr.size();
                while (l < r) {
                    int m = (l + r)/2;
                    if (arr[m].first < a) l = m + 1;
                    else r = m;
                }
                c += l;
                arr.push_back({i, a});
            }
        }
        cout << c << "\n";
    }
    return 0;
}
