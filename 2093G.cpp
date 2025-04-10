#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;

/*
- if k == 0, print 1 and continue
- else, for each set bit in k (and for the remaining suffix of 0s):
    - let pk be the prefix of k up to the current bit
    - iterate through array and let tmp = a_i&pk
    - keep a map for all possible values of tmp, where for all j, map[tmp] stores the index i of 
      the most recent element such that the j-th bit is set/not set in a_i, or -INF if DNE
    - go from index of last set bit - 1 to the index of current bit + 1, inclusive
        - for the current bit j, check if the opposite exists in map[k^tmp], and set ans accordingly
        - update in map[tmp]
- if not already checked, check all pairs i,j such that a_i^a_j=k (similar to what was done before)

O(nlog^2k)
*/

int t;
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        
    }
    return 0;
}