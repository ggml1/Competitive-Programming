#include <bits/stdc++.h>

using namespace std;

const int fire = 0, water = 1, air = 2, N = 1500;

int t, hp, armor;
int dp[N][N][3];

int solve(int h, int a, int cur){
	if(h <= 0 || a <= 0) return 0;

	if(dp[h][a][cur] != -1){
		return dp[h][a][cur];
	}

	switch(cur){
		case water:
			return dp[h][a][cur] = max(solve(h - 20, a + 5, fire), solve(h + 3, a + 2, air)) + 1;
		case fire:
			return dp[h][a][cur] = max(solve(h - 5, a - 10, water), solve(h + 3, a + 2, air)) + 1;
		case air:
			return dp[h][a][cur] = max(solve(h - 20, a + 5, fire), solve(h - 5, a - 10, water)) + 1;
	}
}

int main(){
	ios::sync_with_stdio(0);

	cin >> t;

	while(t--){
		cin >> hp >> armor;

		memset(dp, -1, sizeof(dp));

		int f = solve(hp - 20, armor + 5, fire);

		memset(dp, -1, sizeof(dp));

		int w = solve(hp - 5, armor - 10, water);

		memset(dp, -1, sizeof(dp));

		int a = solve(hp + 3, armor + 2, air);

		cout << max(f, max(w, a)) << endl;
	}

	return 0;
}