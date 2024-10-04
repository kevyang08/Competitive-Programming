#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
count the number of subsequences in the form e, e, e, ... and o, o, e, o, o, e, ...
for first type, let m be the number of evens. then, ans is 2^m - m*(m - 1)/2 - m - 1
for second type, keep track of the number of sequences ending with ooe, oeo, eoo

just keep track of number of o and e
same for oo, oe, eo

for each ooe, keep track of oo + e and eoo...eoo + e
for each oeo, keep track of oe + o and ooe...ooe + o
for each eoo, keep track of eo + o and oeo...oeo + o

could also do dp for e but nah
*/

const int M = 998244353;

int n, a;
ll dp[9][200001], e = 1, c = 0;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int j = 0; j < 9; j++) dp[j][i] = dp[j][i - 1];
        if (a & 1) {
            dp[0][i] = (dp[0][i] + 1)%M;
            dp[1][i] = (dp[1][i] + 1)%M;
            dp[3][i] = (dp[3][i] + dp[0][i - 1])%M;
            dp[5][i] = (dp[5][i] + dp[2][i - 1])%M;
            dp[7][i] = (dp[7][i] + dp[4][i - 1] + dp[6][i - 1])%M;
            dp[8][i] = (dp[8][i] + dp[5][i - 1] + dp[7][i - 1])%M;
        }
        else {
            ++c;
            e = (e << 1)%M;
            dp[2][i] = (dp[2][i] + 1)%M;
            dp[4][i] = (dp[4][i] + dp[1][i - 1])%M;
            dp[6][i] = (dp[6][i] + dp[3][i - 1] + dp[8][i - 1])%M;
        }
    }
    cout << (dp[6][n] + dp[7][n] + dp[8][n] + e - (c * (c - 1)/2)%M - c - 1)%M << "\n";
    return 0;
}