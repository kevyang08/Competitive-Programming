#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s = "aeiou";
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n/5 + (i < n%5); j++) cout << s[i];
        }
        cout << "\n";
    }
    return 0;
}

/*
aeiouu
aeioouu
*/