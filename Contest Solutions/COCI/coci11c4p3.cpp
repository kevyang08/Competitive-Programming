#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    deque<char> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && k && dq.back() < s[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }
    n = dq.size();
    for (int i = 0; i < n - k; i++) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << "\n";
    return 0;
}
