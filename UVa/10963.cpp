#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int t; cin >> t;

	while(t--){
		int w; cin >> w;

		set<int> dif;

		for(int i = 0; i < w; ++i){
			int x, y; cin >> x >> y;

			dif.insert(abs(x - y));
		}

		if(dif.size() == 1) cout << "yes" << endl;
		else cout << "no" << endl;

		if(t) cout << endl;
	}

	return 0;
}