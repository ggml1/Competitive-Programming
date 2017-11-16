#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int ms = 2121;
 
int dp[ms][ms];
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
 
    int s, n; cin >> s >> n;
 
    int price[n];
    int weight[n];
 
    for(int i = 0; i < n; ++i){
    	cin >> weight[i] >> price[i];
    }
 
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j <= s; ++j){
    		if(i == 0){
    			if(j == 0) dp[i][j] = 0;
    			else if(j > weight[i]) dp[i][j] = max(dp[i][j-1], price[i]);
    			else dp[i][j] = 0;
    		} else{
    			if(j < weight[i]) dp[i][j] = dp[i-1][j];
    			else dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + price[i]);
    		}
    	}
    }
 
    cout << dp[n-1][s] << endl;
 
    return 0;
}