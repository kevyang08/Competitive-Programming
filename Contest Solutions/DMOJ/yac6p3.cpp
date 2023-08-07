#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, d;
pair<int, int> getCoords(int a, int b) {
    pair<int, int> sA = {min(n, a), max(1, a - n + 1)}, eA = {max(1, a - m + 1), min(m, a)};
    pair<int, int> sB = {min(n, b), min(m, n + m - b)}, eB = {max(1, b - m + 1), max(1, m - b + 1)};
    if (!(sA.second <= sB.second && eA.second >= eB.second)) return {-1, -1};
    int dt = (sB.second - sA.second + sB.first - sA.first)/2, x = sB.first - dt, y = sB.second - dt;
    return {x, y};
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> m;
    cout << "? " << 1 << " " << 1 << '\n';
    cout << flush;
    cin >> a;
    cout << "? " << n << " " << m << '\n';
    cout << flush;
    cin >> b;
    if (n > 1 && m > 1) {
        cout << "? " << 1 << " " << m << '\n';
        cout << flush;
        cin >> c;
        cout << "? " << n << " " << 1 << '\n';
        cout << flush;
        cin >> d;
        a++;
        b = n + m - b - 1;
        c++;
        d = n + m - d - 1;
        auto e = getCoords(a, c), f = getCoords(b, d), g = getCoords(a, d), h = getCoords(b, c);
        if (e.first == -1) {
            e = g;
            f = h;
        }
        int bruh;
        cout << "? " << e.first << " " << e.second << '\n';
        cout << flush;
        cin >> bruh;
        if (bruh) cout << "! " << g.first << " " << g.second << " " << h.first << " " << h.second << '\n';
        else cout << "! " << e.first << " " << e.second << " " << f.first << " " << f.second << '\n';
    }
    else if (n > 1 || m > 1) {
        if (n == 1) cout << "! " << 1 << " " << a + 1 << " " << 1 << " " << m - b << '\n';
        else cout << "! " << a + 1 << " " << 1 << " " << n - b << " " << 1 << '\n';
    }
    else cout << "! 1 1 1 1\n";
    return 0;
}
