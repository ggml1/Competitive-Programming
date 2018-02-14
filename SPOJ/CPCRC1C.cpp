#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int ms = 1e5 + 5;
 
ll dp[10][100][2];
int a, b;
 
ll solve(int cur, int sum, int lim, string digit){
	if(cur == -1) return sum;
 
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
 
	while(cin >> a >> b && a != -1 && b != -1){
		string s1 = to_string(a - 1);
		string s2 = to_string(b);
 
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
 
		cout << solve(s2.size() - 1, 0, 1, s2) - solve(s1.size() - 1, 0, 1, s1) << endl;
	}
	
	return 0;
} 