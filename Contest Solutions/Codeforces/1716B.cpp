#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	cout << n << "\n";
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			if (j > 1) cout << " ";
    			cout << (j == i ? 1 : j < i ? j + 1 : j);
    		}
    		cout << "\n";
    	}
    }
}
