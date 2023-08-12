#include <bits/stdc++.h>
using namespace std;
 
int t, n, m, a;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n;
        long long sum = 0;
        vector<int> v1, v2;
        for (int i = 0; i < n; i++) {
            cin >> m;
            int m1 = 0x3f3f3f3f, m2 = 0x3f3f3f3f;
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (a <= m1) {
                    m2 = m1;
                    m1 = a;
                }
                else if (a < m2) m2 = a;
            }
            v1.push_back(m1);
            v2.push_back(m2);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sum += v1[0];
        for (int i = 1; i < n; i++) sum += v2[i];
        cout << sum << "\n";
    }
    return 0;
}
