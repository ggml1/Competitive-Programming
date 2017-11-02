#include <bits/stdc++.h>

using namespace std;

const int ms = 2e7 + 1;
int dp[ms];

int main(){
	ios::sync_with_stdio(0);

	int t; cin >> t;
	int kse = 0;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i = 4; i < ms; ++i){
		if(i%6 == 0) dp[i] = min(dp[i/2] + 1, dp[i/3] + 1);
		if(i%2 == 0) dp[i] = min(dp[i-1] + 1, dp[i/2] + 1);
		else if(i%3 == 0) dp[i] = min(dp[i-1] + 1, dp[i/3] + 1);
		else dp[i] = dp[i-1] + 1;
	}

	while(t--){
		kse++;
		int n; cin >> n;
		cout << "Case " << kse << ": " << dp[n] << endl;
	}

	return 0;
}