#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		int lo = INT_MAX, hi = INT_MIN;

		for(int i = 0; i < n; ++i){
			int x; cin >> x;

			lo = min(lo, x);
			hi = max(hi, x);
		}

		cout << 2*(hi - lo) << endl;
	}

    return 0;
}