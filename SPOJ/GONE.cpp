#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int ms = 100;

bool sieve[ms];
ll dp[10][100][2];
int a, b;

void erat(){
	memset(sieve, 1, sizeof(sieve));

	sieve[1] = sieve[0] = 0;

	for(int i = 2; i < ms; ++i){
		if(sieve[i]){
			for(int j = i + i; j < ms; j += i){
				sieve[j] = 0;
			}
		}
	}
}
 
ll solve(int cur, int sum, int lim, string digit){
	if(cur == -1) return sieve[sum];
 
	if(dp[cur][sum][lim] != -1 && !lim) return dp[cur][sum][lim];
 
	ll ret = 0;
 
	int bound = (lim ? digit[cur] - '0' : 9);
 
	for(int i = 0; i <= bound; ++i){
		int nL = (digit[cur] - '0' == i) && lim;
 
		ret += solve(cur - 1, sum + i, nL, digit);
	}
 
	if(!lim) dp[cur][sum][lim] = ret;
 
	return ret;
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
 
	memset(dp, -1, sizeof(dp));
	erat();

	int t; cin >> t;

	while(t--){
		cin >> a >> b;

		string s1 = to_string(a - 1);
		string s2 = to_string(b);
		
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		
		cout << solve(s2.size() - 1, 0, 1, s2) - solve(s1.size() - 1, 0, 1, s1) << endl;
	}
	
	return 0;
} 