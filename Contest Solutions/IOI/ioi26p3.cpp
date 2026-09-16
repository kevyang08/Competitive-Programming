#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
// const int M = 998244353;
const int M = 1e9 + 7;

int idr[4];
int idc[4];
int n, m;
void init(int N, int M) {
    n = N;
    m = M;
    idc[0] = idc[2] = 0;
    idr[0] = idr[1] = 0;
    idc[1] = idc[3] = 2 * M - 2;
    idr[2] = idr[3] = 2 * N - 2;
}
pair<int, int> receive_block(int TL, int TR, int BL, int BR) {
    pair<int, int> res;
    if (!TL) {
        res = {idr[3], idc[3]};
        idc[3] -= 2;
    }
    else if (!TR) {
        res = {idr[2], idc[2]};
        idc[2] += 2;
    }
    else if (!BL) {
        res = {idr[1], idc[1]};
        idc[1] -= 2;
    }
    else if (!BR) {
        res = {idr[0], idc[0]};
        idc[0] += 2;
    }
    if (idc[3] < idc[2]) {
        idr[3] -= 2, idr[2] -= 2;
        idc[2] = 0;
        idc[3] = 2 * m - 2;
    }
    else if (idc[1] < idc[0]) {
        idr[1] += 2, idr[0] += 2;
        idc[0] = 0;
        idc[1] = 2 * m - 2;
    }
    if (idr[3] == idr[1]) idc[1] = idc[3] = min(idc[1], idc[3]);
    if (idr[2] == idr[0]) idc[0] = idc[2] = max(idc[0], idc[2]);
    return res;
}