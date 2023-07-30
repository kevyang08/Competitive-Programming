#include <bits/stdc++.h>
using namespace std;

int n, bruh[1000001], thing[1000001], dp[2][1000001];
string s, t;
deque<pair<int, int>> dq3, dq4;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> n >> s >> t;
    dq3.push_back({0, 0});
    dq4.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        bruh[i] = bruh[i - 1] + ((s[i - 1] - '0') ^ 1); // psa of number of 0s in string s
        thing[i] = thing[i - 1] + (t[i - 1] - '0'); // psa of number of 1s in string t
        if (dq3.front().second < i - 3) dq3.pop_front();
        if (dq4.front().second < i - 4) dq4.pop_front();
        if (s[i - 1] != t[i - 1]) dp[0][i] = dp[1][i] = (s[i - 1] == '0' ? dp[0][i - 1] + 1 : 0x3f3f3f3f);
        else dp[0][i] = dp[1][i] = dp[0][i - 1];
        if (i >= 3) dp[1][i] = min(dp[1][i], dp[1][dq3.front().second] + dq3.front().second - (i - 3) + bruh[i] - bruh[dq3.front().second] + thing[i] - thing[dq3.front().second] + 1);
        if (i >= 4) dp[1][i] = min(dp[1][i], dp[1][dq4.front().second] + dq4.front().second - (i - 4) + bruh[i] - bruh[dq4.front().second] + thing[i] - thing[dq4.front().second] + 1);
        dp[0][i] = dp[1][i];
        while (!dq3.empty() && dq3.back().first >= dp[1][i] + i - dq3.back().second) dq3.pop_back();
        dq3.push_back({dp[1][i], i});
        while (!dq4.empty() && dq4.back().first >= dp[1][i] + i - dq4.back().second) dq4.pop_back();
        dq4.push_back({dp[1][i], i});
    }
    cout << dp[1][n] << "\n";
    return 0;
}

/* bruh
5
11001
00000
*/
