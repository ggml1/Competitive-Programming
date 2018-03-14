#include <bits/stdc++.h>

using namespace std;

const int shirtConst = 40;
const int MAXN = 80;
const int source = 50, sink = 60;

const int inf = 123456789;

typedef pair<int, int> pii;

struct Edge{
	int to, cap, id;

	Edge(int t = 0, int c = 0, int i = 0) :
		to(t), cap(c), id(i) {}
};

map<string, int> shirtID;
vector<Edge> adj[MAXN];

void add(int from, int to, int cap){
	adj[from].push_back(Edge(to, cap, adj[to].size()));
	adj[to].push_back(Edge(from, 0, adj[from].size()));
}

void init(int n){
	for(int i = 0; i < MAXN; ++i){
		adj[i].clear();
	}

	shirtID["XXL"] = 40;
	shirtID["XL"] = 41;
	shirtID["L"] = 42;
	shirtID["M"] = 43;
	shirtID["S"] = 44;
	shirtID["XS"] = 45;

	for(int i = 0; i < 6; ++i){
		add(source, shirtConst + i, n);
	}
}

int augment(){
	queue<int> q;

	bool seen[MAXN];

	memset(seen, 0, sizeof(seen));

	pair<int, pair<pii, int>> p[MAXN];

	seen[source] = 1;
	p[source] = {-1, {{-1, -1}, -1}};

	q.push(source);

	while(!q.empty()){
		int from = q.front();
		q.pop();

		for(int i = 0; i < adj[from].size(); ++i){
			Edge x = adj[from][i];

			int to = x.to;
			int cap = x.cap;
			int curID = i;
			int revID = x.id;

			if(cap > 0 && !seen[to]){
				seen[to] = 1;
				p[to] = {from, {{curID, revID}, cap}};
				q.push(to);
			}
		}
	}

	if(!seen[sink]) return 0;

	int v = sink;

	int flow = inf;

	while(p[v].first != -1){
		flow = min(flow, p[v].second.second);

		v = p[v].first;
	}

	v = sink;

	while(p[v].first != -1){
		int to = v;
		int from = p[v].first;
		int curID = p[v].second.first.first;
		int revID = p[v].second.first.second;

		adj[from][curID].cap -= flow;
		adj[to][revID].cap += flow;

		v = p[v].first;
	}

	return flow;
}

int getMF(){
	int flow = 0;
	int curFlow;

	while((curFlow = augment()) != 0){
		flow += curFlow;
	}

	return flow;
}

int main(){
	ios::sync_with_stdio(0);
	//: Volunteers: 0 through 29 (30 total).
	//: XXL, XL, L, M , S, and XS.
	//:   40,  41, 42, 43,  44,      45.

	int t; cin >> t;

	while(t--){
		int n, m; cin >> n >> m;

		n /= 6;

		init(n);

		for(int i = 0; i < m; ++i){
			string sz1, sz2; cin >> sz1 >> sz2;

			add(i, sink, 1);
			add(shirtID[sz1], i, 1);
			add(shirtID[sz2], i, 1);
		}


		int flow = getMF();

		if(flow == m) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}