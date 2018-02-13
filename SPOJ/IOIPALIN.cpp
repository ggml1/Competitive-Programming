#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 5050;

int n, dp[N][N];
string s;

int solve(int i, int j){
	if(i > j) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	if(i == j) return dp[i][j] = 0;

	if(s[i] == s[j]) return dp[i][j] = solve(i + 1, j - 1);

	return dp[i][j] = min(1 + solve(i, j - 1), 1 + solve(i + 1, j));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> s;

	memset(dp, -1, sizeof(dp));

	cout << solve(0, n - 1) << endl;
	
	return 0;
}