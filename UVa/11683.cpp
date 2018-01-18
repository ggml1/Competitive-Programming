#include <bits/stdc++.h>

using namespace std;

const int ms = 1e4 + 5;

int r, c, h, ans;
int mat[ms][ms], row[ms];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	while(cin >> r && r != 0){
		cin >> c;

		ans = 0;

		for(int i = 1; i <= c; ++i){
			cin >> h;
			for(int j = 0; j < r; ++j){
				if(i == 1) row[j] = 0;

				if(j < h){
					if(row[j] > 0) ans++;
						row[j] = 0;
				} else row[j]++;

				if(i == c && row[j] > 0) ans++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}