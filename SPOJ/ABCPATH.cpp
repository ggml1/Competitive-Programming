#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 52;

char tab[N][N];
int n, m, dp[N][N];

int mx[] = { 0,  0,  1, 1, 1, -1, -1, -1 };
int my[] = { 1, -1, -1, 1, 0, -1,  1,  0 };

vector<pii> starts;

bool valid(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}

int dfs(int x, int y){
	vis[x][y] = 1;

	if(dp[x][y] != -1){
		return dp[x][y];
	}

	int ret = 0;

	for(int i = 0; i < 8; ++i){
		int px = x + mx[i];
		int py = y + my[i];

		if(valid(px, py) && tab[px][py] == tab[x][y] + 1){
			ret = max(ret, 1 + dfs(px, py));
		}
	}

	return dp[x][y] = ret;
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int number = 0;

	while(cin >> n >> m && (n || m)){
		++number;

		starts.clear();

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> tab[i][j];

				if(tab[i][j] == 'A'){
					starts.push_back({i, j});
				}
			}
		}

		if(starts.size() == 0) cout << "Case " << number << ": " << 0 << endl;
		else{
			memset(dp, -1, sizeof(dp));

			int ans = 0;

			for(auto k : starts){
				ans = max(ans, 1 + dfs(k.first, k.second));
			}

			cout << "Case " << number << ": " << ans << endl;
		}
	}

	return 0;
} 