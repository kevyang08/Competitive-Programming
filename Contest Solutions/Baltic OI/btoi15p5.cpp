/*
https://dmoj.ca/problem/btoi15p5
- when played optimally, opponent will always get all elements in the subarray of length n/2 with maximum sum
- since the player goes first, the goal is to choose an element such that without it, the sum of the opponent's
  subarray (the one with the greatest sum) is minimized
*/

#include <bits/stdc++.h>
using namespace std;

int n, ln, v[1000001], ans = 0, mn = 0x3f3f3f3f, l[1000001], r[1000001];
deque<int> dq;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    ln = n/2;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
        ans += v[i];
    }
    for (int i = 1; i <= 2 * n; i++) v[i] += v[i - 1];
    for (int i = ln; i < 2 * n; i++) {
        // if the current maximum sum subarray from the left contains the element at index i + 1
        // since the sum would be anywhere from v[i + 1] - v[i - ln + 1] to v[i + ln] - v[i]
        if (!dq.empty() && dq.front() - ln + n <= i && dq.front() + n > i) dq.pop_front();
        while (!dq.empty() && v[dq.back()] - v[dq.back() - ln] <= v[i] - v[i - ln]) dq.pop_back();
        dq.push_back(i);
        l[i + 1] = v[dq.front()] - v[dq.front() - ln];
    }
    for (int i = 1; i <= ln; i++) l[i] = l[i + n];
    dq.clear();
    for (int i = 2 * n - ln; i > 0; i--) {
        // if the current maximum sum subarray from the right contains the element at index i
        // since the sum would be anywhere from v[i + ln - 1] - v[i - 1] to v[i] - v[i - ln]
        if (!dq.empty() && dq.front() - n >= i && dq.front() - ln - n < i) dq.pop_front();
        while (!dq.empty() && v[dq.back()] - v[dq.back() - ln] <= v[i + ln] - v[i]) dq.pop_back();
        dq.push_back(i + ln);
        r[i] = v[dq.front()] - v[dq.front() - ln];
    }
    for (int i = 2 * n; i > 2 * n - ln; i--) r[i] = r[i - n];
    for (int i = 1; i <= 2 * n; i++) mn = min(mn, max(l[i], r[i]));
    cout << ans - mn << "\n";
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure question was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
