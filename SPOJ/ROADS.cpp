#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
const int N = 1010;
const int C = 10101;
const int inf = 123456789;

vector<pair<int, pii>> adj[N];
int dp[N][C];

int solve(int cur, int has, int n){
    if(cur == n) return 0;

    if(dp[cur][has] != -1) return dp[cur][has];

    dp[cur][has] = inf;

    for(auto v : adj[cur]){
        int to = v.first;
        int d = v.second.first;
        int cost = v.second.second;

        if(cost <= has){
            dp[cur][has] = min(dp[cur][has], solve(to, has - cost, n) + d);
        }
    }

    return dp[cur][has];
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
 
    int t; cin >> t;
 
    while(t--){
        int k, n, r; cin >> k >> n >> r;

        for(int i = 1; i <= n; ++i){
            adj[i].clear();
        }
 
        for(int i = 0; i < r; ++i){
            int s, d, l, toll; cin >> s >> d >> l >> toll;

            adj[s].push_back({d, {l, toll}});
        }

        memset(dp, -1, sizeof(dp));

        int ans = solve(1, k, n);

        if(ans == inf) cout << -1 << endl;
        else cout << ans << endl;
    }
 
    return 0;
}