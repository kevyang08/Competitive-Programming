#include <bits/stdc++.h>
using namespace std;

int c, bruh[3][200001], t = 0; 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> c;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> bruh[i][j];
            if (bruh[i][j]) t += 3;
            if (j%2 == 1 && bruh[i][j] && bruh[i - 1][j]) t -= 2;
            if (bruh[i][j] && bruh[i][j - 1]) t -= 2;
        }
    }
    cout << t << "\n";
    return 0;
}
