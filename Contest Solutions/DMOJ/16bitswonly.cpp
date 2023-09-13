#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b, c;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        cout << (a * b != c ? "16 BIT S/W ONLY" : "POSSIBLE DOUBLE SIGMA") << "\n";
    }
    return 0;
}
