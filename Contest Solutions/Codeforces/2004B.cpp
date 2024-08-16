#include <bits/stdc++.h>
using namespace std;

int t, la, ra, lb, rb;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> la >> ra >> lb >> rb;
        if (la > rb || lb > ra) cout << "1\n";
        else if (la == lb && ra == lb) cout << ra - la << "\n";
        else if (rb >= ra && ra >= lb) cout << min(ra - lb + 1, ra - la + (lb < la)) + (rb > ra) << "\n";
        else cout << min(rb - la + 1, rb - lb + (la < lb)) + (ra > rb) << "\n";
    }
    return 0;
}