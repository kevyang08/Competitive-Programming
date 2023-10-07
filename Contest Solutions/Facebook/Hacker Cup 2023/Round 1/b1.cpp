#include <bits/stdc++.h>
using namespace std;

int t, p;
bool prime[100001];
int getPrime(int n) {
    for (int i = (int)sqrt(n); i > 1; i--) if (n%i == 0 && prime[i]) return i;
    return n;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    freopen("sum_41_chapter_1_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for (int i = 2; i <= 35000; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 35000; j += i) prime[j] = false;
    }
    cin >> t;
    for (int bruh = 1; bruh <= t; bruh++) {
        cin >> p;
        stack<int> ans;
        int sum = 0;
        while (p > 1) {
            int temp = getPrime(p);
            ans.push(temp);
            sum += temp;
            p /= temp;
        }
        if (sum > 41) {
            cout << "Case #" << bruh << ": -1\n";
            continue;
        }
        while (sum < 41) {
            ans.push(1);
            sum++;
        }
        cout << "Case #" << bruh << ": " << ans.size();
        while (!ans.empty()) {
            cout << " " << ans.top();
            ans.pop();
        }
        cout << "\n";
    }
    return 0;
}
