#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 5002;
const ll inf = 1e18;

map<int, map<int, ll>> cap;

vector<int> adj[MAXN];

void init(){
	for(int i = 0; i < MAXN; ++i){
		adj[i].clear();
	}

	cap.clear();
}

void add(int from, int to, ll garg){
	adj[from].push_back(to);
	adj[to].push_back(from);

	cap[to][from] = cap[from][to] = (cap[from][to] + garg);
}

ll augment(int s, int t){
	queue<int> q;

	pair<int, ll> p[MAXN];

	bool seen[MAXN];

	memset(seen, 0, sizeof(seen));

	p[s] = {-1, -1LL};

	seen[s] = 1;

	q.push(s);

	while(!q.empty()){
		int from = q.front();
		q.pop();

		for(int to : adj[from]){
			if(!seen[to] && cap[from][to] > 0){
				seen[to] = 1;
				p[to] = {from, cap[from][to]};
				q.push(to);
			}
		}

	}

	if(!seen[t]) return 0;

	int v = t;

	ll flow = inf;

	while(p[v].first != -1){
		flow = min(flow, p[v].second);

		v = p[v].first;
	}

	v = t;

	while(p[v].first != -1){
		int to = v;
		int from = p[v].first;

		cap[from][to] -= flow;
		cap[to][from] += flow;

		v = p[v].first;
	}

	return flow;
}

ll getMF(int n){
	ll flow, curFlow = flow = 0;

	while((curFlow = augment(1, n)) != 0){
		flow += curFlow;
	}

	return flow;
}

int main(){
	// ios::sync_with_stdio(0);
	
	int n, m; scanf("%d%d", &n, &m);

	init();

	for(int i = 0; i < m; ++i){
		int a, b;
		ll c;

		scanf("%d%d %lld", &a, &b, &c);

		add(a, b, c);
	}

	printf("%lld\n", getMF(n));

	return 0;
}