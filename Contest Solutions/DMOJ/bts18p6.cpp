#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
int n, t;
long long psa[3][MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int l, r, a, b, c;
        cin >> l >> r >> a >> b >> c; l--;
        psa[0][l] += a;
        psa[0][r] -= a;
        psa[1][l] += b - 2 * a * l;
        psa[1][r] -= b - 2 * a * l;
        psa[2][l] += c - b * l + (long long)a * l * l;
        psa[2][r] -= c - b * l + (long long)a * l * l;
    }
    for (int i = 0; i < t; i++) {
        psa[0][i] += psa[0][i - 1];
        psa[1][i] += psa[1][i - 1];
        psa[2][i] += psa[2][i - 1];
        cout << psa[0][i] * i * i + psa[1][i] * i + psa[2][i] << " ";
    }
}
