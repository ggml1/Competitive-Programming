#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int MO = 22, MN = 81, N = 1010;
const int inf = 123456789;

typedef struct Cilinder {
	int ox, ni, w;

	void read() {
		cin >> ox >> ni >> w;
	}
} Cilinder;

Cilinder cil[N];
int dp[MO][MN][N];

int solve(int ox, int ni, int cur, int n) {
	ox = max(ox, 0);
	ni = max(ni, 0);

	if(ox == 0 && ni == 0) return 0;
	
	if(cur == n) return inf;

	if(dp[ox][ni][cur] != -1) return dp[ox][ni][cur];

	return dp[ox][ni][cur] = min(solve(ox, ni, cur + 1, n),
								 solve(ox - cil[cur].ox, ni - cil[cur].ni, cur + 1, n) + cil[cur].w);
}

int main() {
	ios::sync_with_stdio(0);

    int c; cin >> c;

    while (c--) {
    	int ox, ni; cin >> ox >> ni;

    	int n; cin >> n;

    	for (int i = 0; i < n; ++i) {
    		cil[i].read();
    	}

    	memset(dp, -1, sizeof dp);

    	cout << solve(ox, ni, 0, n) << endl;
    }
    
    return 0;
}
