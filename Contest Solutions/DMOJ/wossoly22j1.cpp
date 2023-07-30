#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> a >> b >> c;
    if (a + 4 * b + 7 * c <= n) cout << "Time to go shopping!\n";
    else cout << "You cannot afford them all.\n";
}
