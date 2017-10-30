#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mxv = int(1e5) + 1;
const int mxc = int(1e3) + 1;

int dp[mxc][mxv];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int v, m; cin >> v >> m;

    m++;

    int coins[m];

    for(int i = 0; i < m-1; ++i) cin >> coins[i];

    coins[m-1] = 0;

    sort(coins, coins + m);

    for(int i = 0; i < m; ++i){
        for(int j = 0; j <= v; ++j){
            if(j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = 0;
            else{
                if(j%coins[i] == 0) dp[i][j] = 1;
                dp[i][j] = dp[i-1][j] || (j - coins[i] >= 0 ? dp[i-1][j - coins[i]] : 0);
            }
        }
    }

    if(dp[m-1][v]) cout << "S" << endl;
    else cout << "N" << endl;
}