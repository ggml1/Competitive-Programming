#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int t; cin >> t;
	int kse = 0;

	while(t--){
		int n; cin >> n;
		++kse;

		int x[n];

		int ans = INT_MIN;

		for(int i = 0; i < n; ++i){
			cin >> x[i];

			ans = max(x[i], ans);
		}

		cout << "Case " << kse << ": " << ans << endl;
	}

    return 0;
}