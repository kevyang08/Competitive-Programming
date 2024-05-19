#include <bits/stdc++.h>
using namespace std;

// time to solve: ~1h30
// probably faster to use ternary search

/*
https://dmoj.ca/problem/aac7p3

- preprocess the array to check distance from nearest portal (from behind or ahead) as array d
    - if no portal, simply calculate the distance from first checkpoint
- keep track of total distance and total checkpoints left
- group checkpoints by how they're separated by portals (each groups starts at a new portal/checkpoint 1)
- go through each checkpoint in order
    - if is new group, add all checkpoints in group to queue
    - if direct distance is less than or equal to distance from nearest portal + distance of curr checkpoint from nearest portal, 
        subtract from total distance and add it to separate total, total checkpoints left--, as well as separate cnt++
    - ans += d[i] * total left + total distance + separate total
    - before advancing, subtract a[i] * cnt from separate total
    - separate cnt--
*/

const int M = 1e9 + 7;

int n, m, x, a[1000005], c, dc = 0;
long long d[1000005], psa[1000005], curr, s, ds = 0, ans = 0;
bool p[1000005];
queue<int> q;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> m;
    c = n;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        p[x] = true;
    }
    curr = p[1] ? 0 : 0x3f3f3f3f;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        psa[i] = a[i] + psa[i - 1];
        curr += a[i];
        if (p[i]) curr = 0;
        d[i] = curr;
    }
    curr = p[n] ? 0 : 0x3f3f3f3f;
    d[1] = 0x3f3f3f3f;
    s = d[n];
    for (int i = n - 1; i > 0; i--) {
        curr += a[i + 1];
        if (p[i]) curr = 0;
        d[i] = min(d[i], curr);
        s = (s + d[i])%M;
    }
    for (int i = 1, j = 1; i < n; i++) {
        ds -= a[i] * dc;
        if (dc) dc--;
        if (p[i] || i == 1) {
            q.push(j++);
            while (j <= n && !p[j]) q.push(j++);
        }
        while (!q.empty() && psa[q.front()] - psa[i] <= d[i] + d[q.front()]) {
            s = (s - d[q.front()] + M)%M;
            ds += psa[q.front()] - psa[i];
            c--;
            if (q.front() > i) dc++;
            q.pop();
        }
        ans = (ans + d[i] * c + s + ds)%M;
        // cout << i << " " << ans << " " << d[i] << " " << c << " " << s << " " << ds << " what\n";
    }
    cout << ans << "\n";
    return 0;
}
