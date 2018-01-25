#include <bits/stdc++.h>

using namespace std;

const int N = 250;

int m, n, t;
int dp[N][N][2];
char mat[N][N];

int solve(int x, int y, int on){
	if(x < 0 || x >= m || y < 0 || y >= n || mat[x][y] == '#') return 0;

	if(dp[x][y][on] != -1) return dp[x][y][on];

	if(on) return dp[x][y][on] = max(solve(x, y + 1, on), solve(x + 1, y, 0)) + (mat[x][y] == 'T');

	return dp[x][y][on] = max(solve(x, y - 1, on), solve(x + 1, y, 1)) + (mat[x][y] == 'T');
}

int main(){
	ios::sync_with_stdio(0);

	cin >> t;

	while(t--){
		cin >> m >> n;

		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				cin >> mat[i][j];
			}
		}

		memset(dp, -1, sizeof(dp));

		cout << solve(0, 0, 1) << endl;
	}

	return 0;
}