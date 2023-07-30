#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int g, p, t, c = 0;
    set<int, greater<int>> s;
    cin >> g >> p;
    for (int i = 1; i <= g; i++) s.insert(i);
    while (p--) {
        cin >> t;
        if (s.lower_bound(t) != s.end() && *s.lower_bound(t) <= t) {
            c++;
            s.erase(*s.lower_bound(t));
        }
        else break;
    }
    cout << c << "\n";
    return 0;
}
