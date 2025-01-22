#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

int n;
string s;
deque<int> st;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (char c : s) st.push_back(c - '0');
    while (n--) {
        stack<int> tmp;
        int prv = st.back(), cnt = 0;
        while (!st.empty()) {
            int cur = st.back(); st.pop_back();
            if (prv != cur) {
                tmp.push(prv);
                // tmp.push(cnt);
                while (cnt) {
                    tmp.push(cnt%10);
                    cnt /= 10;
                }
                prv = cur;
            }
            ++cnt;
        }
        while (cnt) {
            st.push_back(cnt%10);
            cnt /= 10;
        }
        st.push_back(prv);
        while (!tmp.empty()) st.push_back(tmp.top()), tmp.pop();
    }
    while (!st.empty()) {
        cout << st.front();
        st.pop_front();
    }
    cout << "\n";
    return 0;
}