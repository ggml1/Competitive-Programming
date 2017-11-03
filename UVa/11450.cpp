#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oi() cout << "oi\n";
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 0x3f3f3f3f;
const int ms = 300;
const int ms2 = 21;

int dp[ms2][ms2][ms];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(4);

    int n; cin >> n;

    while(n--){
    	int m, c; cin >> m >> c;

    	vector<int> garms[c];
    	int sizes[c];

    	for(int i = 0; i < c; ++i){
    		cin >> sizes[i];
    		for(int j = 0; j < sizes[i]; ++j){
    			int x; cin >> x;
    			garms[i].push_back(x);
    		}
    		sort(garms[i].begin(), garms[i].end());
    	}

    	for(int i = 0; i < c; ++i){
    		for(int j = 0; j < ms2; ++j){
    			for(int k = 0; k <= m; ++k){
    				if(k == 0){
    					dp[i][j][k] = 0;
    					continue;
    				}
    				if(i == 0){
    					if(j == 0){
    						if(garms[i][j] <= k) dp[i][j][k] = garms[i][j];
    						else dp[i][j][k] = 0;
    					} else if(j < sizes[i]){
    						if(garms[i][j] <= k) dp[i][j][k] = max(garms[i][j], dp[i][j-1][k]);
    						else dp[i][j][k] = max(dp[i][j][k-1], dp[i][j-1][k]);
    					} else dp[i][j][k] = max(dp[i][j][k-1], dp[i][j-1][k]);
    				} else{
    					if(j == 0){
    						if(garms[i][j] <= k){
    							int b4 = dp[i-1][ms2 - 1][k - garms[i][j]];
    							if(b4 != 0){
    								dp[i][j][k] = max(b4 + garms[i][j], dp[i][j][k-1]);
    							} else dp[i][j][k] = dp[i][j][k-1];
    						} else dp[i][j][k] = dp[i][j][k-1];
    					} else if(j < sizes[i]){
    						if(garms[i][j] <= k){
    							int b4 = dp[i-1][ms2 - 1][k - garms[i][j]];
    							if(b4 != 0){
    								dp[i][j][k] = max(b4 + garms[i][j], dp[i][j-1][k]);
    							} else dp[i][j][k] = max(dp[i][j-1][k], dp[i][j][k-1]);
    						} else dp[i][j][k] = max(dp[i][j-1][k], dp[i][j][k-1]);
    					} else dp[i][j][k] = dp[i][j-1][k];
    				}
    			}
    		}
    	}
    	
    	if(dp[c-1][ms2-1][m] == 0) cout << "no solution" << endl;
    	else cout << dp[c-1][ms2-1][m] << endl;
    }

    return 0;
}