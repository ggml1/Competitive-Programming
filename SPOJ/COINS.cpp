#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int ms = 1e5 + 5;

ll dp[ms];

ll solve(ll x){
	if(x == 0) return 0;

	if(x >= ms) return solve(x/2) + solve(x/3) + solve(x/4);

	if(dp[x] != -1) return dp[x];

	return dp[x] = max(x, solve(x/2) + solve(x/3) + solve(x/4));
}

int main(){
	ll n;

	memset(dp, -1, sizeof(dp));

	while(scanf("%lld", &n) != EOF){
		cout << solve(n) << endl;
	}
	
	return 0;
}