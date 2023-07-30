#include <bits/stdc++.h>
using namespace std;

int a[200000], b[200000];
bool compa(int i, int j) {return a[i] != a[j] ? a[i] < a[j] : b[i] > b[j];}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, c = 0, ans = 0;
    vector<int> id;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] <= c || b[i] == 0) c++;
        else id.push_back(i);
    }
    sort(id.begin(), id.end(), compa);
    for (int i = id.size() - 1; i >= 0; i--) {
        pq.push(b[id[i]]);
        if (c + i < a[id[i]]) {
            ans += pq.top(); pq.pop();
            c++;
        }
    }
    cout << ans << "\n";
}
