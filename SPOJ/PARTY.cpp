#include <bits/stdc++.h>

#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int ms = 2121;

ll dp[123][505];
ll weight[123];
ll price[123];
ll totalW[123][505];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int s, n; cin >> s >> n;

    while(s != 0 || n != 0){
    	for(int i = 1; i <= n; ++i){
    		cin >> weight[i] >> price[i];
    	}

    	memset(dp, 0, sizeof(dp));
    	memset(totalW, 0, sizeof(totalW));

    	for(int i = 1; i <= n; ++i){
    		for(int j = 1; j <= s; ++j){
    			int w = weight[i];
    			int p = price[i];
    			if(w > j){
    				dp[i][j] = dp[i-1][j];
    				totalW[i][j] = totalW[i-1][j];
    			} else{
    				if(dp[i-1][j - w] + p > dp[i-1][j]){
    					totalW[i][j] = w + totalW[i-1][j - w];
    					dp[i][j] = dp[i-1][j - w] + p;
    				} else if(dp[i-1][j - w] + p == dp[i-1][j]){
    					totalW[i][j] = min(totalW[i-1][j], w + totalW[i-1][j - w]);
    					dp[i][j] = dp[i-1][j];
    				} else{
    					dp[i][j] = dp[i-1][j];
    					totalW[i][j] = totalW[i-1][j];
    				}
    			}
    		}
    	}

    	cout << totalW[n][s] << ' ' << dp[n][s] << endl;

    	cin >> s >> n;
    }

    return 0;
}
