#include <bits/stdc++.h>
using namespace std;
 
int n;
string s;
bool thing = false, ans = false;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '|') thing = !thing;
        else if (s[i] == '*' && thing) ans = true;
    }
    cout << (ans ? "in\n" : "out\n");
    return 0;
}
