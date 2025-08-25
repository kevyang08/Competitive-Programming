#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353
const int M = 1e9 + 7;

int n, sz[200005];
vector<int> adj[200005];
void dfs(int i, int p) {
    sz[i] = 1;
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs(j, i);
        sz[i] += sz[j];
    }

}
int get_centroid(int i, int p) {
	for (int j : adj[i]) {
		if (j == p) continue;
		if (sz[j] * 2 > n) return get_centroid(j, i);
	}
	return i;
}