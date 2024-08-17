#include <bits/stdc++.h>
using namespace std;

/*
Euler's totient function: counts the numbers between 1 and n that are coprime to n

Similar to sieve, works in O(nloglogn) time

Reference: https://cp-algorithms.com/algebra/phi-function.html
*/

const int MAXN = 1e7 + 5;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vector<int> phi(MAXN);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i <= MAXN; i++) 
        if (phi[i] == i)
            for (int j = i; j <= MAXN; j += i)
                phi[j] -= phi[j]/i;
    return 0;
}