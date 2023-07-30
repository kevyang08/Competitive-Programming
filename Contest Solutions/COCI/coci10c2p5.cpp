#include <bits/stdc++.h>
using namespace std;

int r, c, g, mn = 0x3f3f3f3f, idr, idc, cr = 0, cc = 0, d = 2;
int test = 0;
void navigate() {
    if (idr == 0) {
        while (cr != r - 1 || cc != c - 1) {
            if (cr == 0) {
                if (d != 0) {
                    cout << 'D';
                    d = 2;
                    cr++;
                }
                else {
                    cout << 'R';
                    d = 1;
                    cc++;
                }
            }
            else if (cr == 1) {
                if (cc == c - 1) {
                    cout << 'D';
                    d = 2;
                    cr++;
                }
                else if (d != 2 && idc != cc) {
                    cout << 'U';
                    d = 0;
                    cr--;
                }
                else {
                    cout << 'R';
                    d = 1;
                    cc++;
                }
            }
            else {
                if (d != 2 && (cc == 0 || cc == c - 1)) {
                    cout << 'D';
                    d = 2;
                    cr++;
                }
                else if (cr%2 == 0) {
                    cout << 'L';
                    d = 3;
                    cc--;
                }
                else {
                    cout << 'R';
                    d = 1;
                    cc++;
                }
            }
        }
    }
    else {
        while (cr != r - 1 || cc != c - 1) {
            if (cr <= idr) {
                if (cr == idr - 1) {
                    if (d != 0 && cc != idc) {
                        cout << 'D';
                        d = 2;
                        cr++;
                    }
                    else if (cr%2 == 0) {
                        cout << 'R';
                        d = 1;
                        cc++;
                    }
                    else {
                        cout << 'L';
                        d = 3;
                        cc--;
                    }
                }
                else if (cr == idr) {
                    if (cc == 0 && cr%2 == 0 || cc == c - 1 && cr%2 == 1) {
                        cout << 'D';
                        d = 2;
                        cr++;
                    }
                    else if (d != 2) {
                        cout << 'U';
                        d = 0;
                        cr--;
                    }
                    else if (cr%2 == 1) {
                        cout << 'R';
                        d = 1;
                        cc++;
                    }
                    else {
                        cout << 'L';
                        d = 3;
                        cc--;
                    }
                }
                else {
                    if (d != 2 && (cc == 0 || cc == c - 1)) {
                        cout << 'D';
                        d = 2;
                        cr++;
                    }
                    else if (cr%2 == 1) {
                        cout << 'L';
                        d = 3;
                        cc--;
                    }
                    else {
                        cout << 'R';
                        d = 1;
                        cc++;
                    }
                }
            }
            else {
                if (d != 2 && (cc == 0 || cc == c - 1)) {
                    cout << 'D';
                    d = 2;
                    cr++;
                }
                else if (cr%2 == 0) {
                    cout << 'L';
                    d = 3;
                    cc--;
                }
                else {
                    cout << 'R';
                    d = 1;
                    cc++;
                }
            }
        }
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> r >> c;
    if (r%2 == 1 || c%2 == 1) {
        if (r%2 == 1) for (int i = 1; i < r * c; i++) cout << (i%c == 0 ? 'D' : i/c%2 == 1 ? 'L' : 'R');
        else for (int i = 1; i < r * c; i++) cout << (i%r == 0 ? 'R' : i/r%2 == 1 ? 'U' : 'D');
    }
    else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> g;
                if (i%2 != j%2 && g < mn) {
                    mn = g;
                    idr = i;
                    idc = j;
                }
            }
        }
        navigate();
    }
    cout << "\n";
    return 0;
}
