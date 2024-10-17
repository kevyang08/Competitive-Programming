#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
        cin >> n >> s;
        queue<int> q;
        vector<long long> v(1, 0);
        long long sum = 0, cnt = 0;
        for (int i = 0; i < n; i++) if (s[i] == 'D') {
            cnt++, sum += i;
            v.push_back(sum);
        }
        sum = 0;
        for (int i = 0, l = 0; i < n; i++) {
            if (s[i] == 'D') {
                l++; cnt--;
                if (q.size() > cnt) {
                    if (q.size() > cnt + 1) {
                        sum -= i - q.front();
                        q.pop();
                    }
                    cout << (v[l + cnt] - v[l] - cnt * i + sum) * 2LL + n - i << " ";
                }
                else cout << (v[l + q.size()] - v[l] - (long long)q.size() * i + sum) * 2LL + i + 1 << " ";
            }
            else {
                if (q.size() < cnt) cout << (v[l + q.size() + 1] - v[l] - (long long)q.size() * i - i + sum) * 2LL + i + 1 << " ";
                else if (q.size() - 1 == cnt) cout << (v[l + cnt] - v[l] - cnt * i + sum - i + q.front()) * 2LL + n - i << " ";
                else cout << (v[l + cnt] - v[l] - cnt * i + sum) * 2LL + n - i << " ";
                q.push(i);
                if (q.size() > cnt + 1) {
                    sum -= i - q.front();
                    q.pop();
                }
            }
            sum += q.size();
        }
        cout << "\n";
    return 0;
}