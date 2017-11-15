#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll mod = 1e9 + 7;
const int ms = 123;
const int mv = 11;
 
ll dp[ms][1 << mv];
 
ll ways(int x, ll mask, ll limit, vector<int> shirts[], int n){
	if(shirts[x].size() == 0) return ways(x+1, mask, limit, shirts, n);
	if(mask == limit){
		return 1;
	}
	
	if(x >= 101) return 0;
	
	if(dp[x][mask] != -1){
		return dp[x][mask];
	}
	
	ll ans = ways(x+1, mask, limit, shirts, n);
	
	for(int j = 0, c = shirts[x].size(); j < c; ++j){
		if(!(mask & (1 << shirts[x][j]))){
			ans += ways(x+1, mask | (1 << shirts[x][j]), limit, shirts, n);
			ans %= mod;
		}
	}
	
	return dp[x][mask] = ans;
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n; cin.ignore();
		
		vector<int> shirts[ms];
		
		for(int i = 0; i < n; ++i){
			int x;
			string k; getline(cin, k);
			stringstream ss(k);
			while(ss >> x){
				shirts[x].push_back(i);
			}
		}
		
		memset(dp, -1, sizeof(dp));
		
		cout << ways(0, 0, (1 << n) - 1, shirts, n) << endl;
	}
	
	return 0;
}
