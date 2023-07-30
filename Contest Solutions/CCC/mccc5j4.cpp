#include <bits/stdc++.h>
using namespace std;

int n, t, c = 0;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*') c++;
        else t += s[i] - 'a' + 1;
    }
    if (t + c > n || t + c * 26 < n) cout << "Impossible\n";
    else {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') cout << s[i];
            else {
                c--;
                char bruh = (char)(max(n - c * 26 - t, 1) + 'a' - 1);
                cout << bruh;
                t += bruh - 'a' + 1;
            }
        }
        cout << "\n";
    }
    return 0;
}
