#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	int n, b, h, w;

	while(cin >> n >> b >> h >> w){
		int hot[h];

		int ans = INT_MAX;

		for(int i = 0; i < h; ++i){
			cin >> hot[i];
			for(int j = 0; j < w; ++j){
				int x; cin >> x;

				if(x >= n){
					ans = min(ans, n*hot[i]);
				}
			}
		}

		if(ans > b) cout << "stay home" << endl;
		else cout << ans << endl;
	}

    return 0;
}