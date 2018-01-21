#include <bits/stdc++.h>

using namespace std;

const int ms = 1030;

int rats[ms][ms], killed[ms][ms];
int n, d, t, ans, px, py;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(2);

	cin >> t;

	while(t--){
		cin >> d >> n;

		memset(rats, 0, sizeof(rats));
		memset(killed, 0, sizeof(killed));

		for(int i = 0; i < n; ++i){
			int x, y, z; cin >> x >> y >> z;

			rats[x][y] = z;
		}

		for(int i = 0; i < 1025; ++i){
			for(int j = 0; j < 1025; ++j){
				if(i == 0){
					if(j == 0) killed[i][j] = rats[i][j];
					else killed[i][j] = rats[i][j] + killed[i][j - 1];
				} else{
					if(j == 0) killed[i][j] = rats[i][j] + killed[i - 1][j];
					else killed[i][j] = killed[i][j - 1] + killed[i - 1][j] - killed[i - 1][j - 1] + rats[i][j];
				}
			}
		}

		ans = 0;

		for(int i = d + 1; i <= 1024 - d; ++i){
			for(int j = d + 1; j <= 1024 - d; ++j){
				int fx = i + d, fy = j + d;
				int sx = i - d - 1, sy = j - d - 1;

				int local = killed[fx][fy] - killed[sx][fy] - killed[fx][sy] + killed[sx][sy];

				if(local > ans){
					ans = local;
					px = i, py = j;
				}
			}
		}

		cout << px << ' ' << py << ' ' << ans << endl;
	}

	return 0;
}