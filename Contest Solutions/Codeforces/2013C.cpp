#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
go all the way right, then go left

for first one:
- check 1
    - if 1, check 11 and 10
    - else string = 000...

    2n - 1 queries till the end
    2n - 1 queries going backwards
*/

int t, n, r;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        string s = "";
        cout << "? 1" << endl;
        cin >> r;
        if (r) {
            s += '1';
            while (true) {
                if (s.length() == n) break;
                cout << "? " << s << 1 << endl;
                cin >> r;
                if (r) {
                    s += '1';
                    continue;
                }
                cout << "? " << s << 0 << endl;
                cin >> r;
                if (r) s += '0';
                else break;
            }
            if (s.length() < n) {
                for (int i = n - s.length() - 1; i >= 0; i--) {
                    cout << "? " << 1 << s << endl;
                    cin >> r;
                    if (r) s = '1' + s;
                    else s = '0' + s;
                }
            }
            cout << "! " << s << endl;
        }
        else {
            cout << "! ";
            for (int i = 0; i < n; i++) cout << 0;
            cout << endl;
        }
    }
    return 0;
}