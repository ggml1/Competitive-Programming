#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 10001;

vector<int> adj[N];
int par[N], l[N], h[N];
int dp[N][100];
map<int, map<int, int>> d;

int getDist(int u, int v){
	if(d.count(u) == 0 || d[u].count(v) == 0) return d[v][u];
	return d[u][v];
}

void dfs(int v, int p){
	if(v != p){
		h[v] = h[p] + getDist(v, p);
		l[v] = l[p] + 1;
	}

	for(int u : adj[v]){
		if(u != p){
			par[u] = v;
			dfs(u, v);
		}
	}
}

int findLCA(int u, int v){
	if(l[u] < l[v]){
		swap(u, v);
	}

	int log;

	for(log = 1; (1 << log) <= l[u]; ++log);

	--log;

	for(int i = log; i >= 0; --i){
		if(l[u] - (1 << i) >= l[v]){
			u = dp[u][i];
		}
	}

	if(u == v) return u;

	for(int i = log; i >= 0; --i){
		if(dp[u][i] != -1 && dp[u][i] != dp[v][i]){
			u = dp[u][i];
			v = dp[v][i];
		}
	}

	return par[u];
}

void calcLCA(int n){
	memset(dp, -1, sizeof(dp));

	for(int i = 1; i <= n; ++i){
		dp[i][0] = par[i];
	}

	for(int j = 1; (1 << j) < n; ++j){
		for(int i = 1; i <= n; ++i){
			if(dp[i][j - 1] != -1){
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
	}
}

int getKth(int node, int k){
	int log;

	for(log = 1; (1 << log) <= l[node]; ++log);

	--log;

	for(int i = log; i >= 0; --i){
		if(l[node] - (1 << i) >= k){
			node = dp[node][i];
		}
	}

	return node;
}

void clear(int n){
	for(int i = 0; i <= n; ++i){
		adj[i].clear();
		par[i] = -1;
		h[i] = 0;
		l[i] = 0;
	}

	d.clear();
}

int main(){

    int t; scanf("%d", &t);

    while(t--){
    	int n; scanf("%d", &n);

    	clear(n);

    	for(int i = 0; i < n - 1; ++i){
    		int a, b, c; scanf("%d%d%d", &a, &b, &c);

    		adj[a].push_back(b);
    		adj[b].push_back(a);

    		d[a][b] = c;
    	}

    	h[1] = 0; l[1] = 0;
    	par[1] = 1;

    	dfs(1, 1);

    	calcLCA(n);

    	char inst[10]; scanf(" %s", inst);

    	while(inst[1] != 'O'){
    		int u, v; scanf("%d%d", &u, &v);

    		int k = findLCA(u, v);

    		if(inst[1] == 'I') printf("%d\n", h[u] + h[v] - 2 * h[k]);
    		else{
    			int kth; scanf("%d", &kth);

    			int x;

    			if(l[u] - l[k] + 1 >= kth) x = getKth(u, l[u] - kth + 1);
    			else x = getKth(v, 2 * l[k] + kth - l[u] - 1);

    			printf("%d\n", x);
    		}

    		scanf(" %s", inst);
    	}
    }

    return 0;
}