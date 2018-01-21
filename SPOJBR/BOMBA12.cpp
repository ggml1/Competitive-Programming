#include <bits/stdc++.h>

using namespace std;

const int N = 501;
const long long inf = 1e18;

int n, e, s, m;
vector<int> adj[3 * N];
long long dist[3 * N];

void bfs(int e){
	queue<int> trr;

	dist[e] = 0;

	trr.push(e);

	while(!trr.empty()){
		int u = trr.front();
		trr.pop();

		for(auto k : adj[u]){
			if(dist[k] == inf){
				dist[k] = dist[u] + 1;
				trr.push(k);
			}
		}
	}
}

void cl(){
	for(int i = 0; i < 3 * N; ++i){
		dist[i] = inf;
	}
}

inline int node(int x){
	return 3 * x;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> e >> s >> m;

	for(int i = 0; i < m; ++i){
		int a, b, t; cin >> a >> b >> t;

		if(t){
			adj[node(a)].push_back(node(b) + 1);
		} else{
			adj[node(a) + 1].push_back(node(b) + 2);
			adj[node(a) + 2].push_back(node(b));
		}
	}

	cl();

	bfs(node(e));

	if(dist[node(s)] == inf && dist[node(s) + 1] == inf && dist[node(s) + 2] == inf) cout << "*" << endl;
	else cout << min(dist[node(s)], min(dist[node(s) + 1], dist[node(s) + 2]));

	return 0;
}