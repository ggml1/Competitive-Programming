#include <bits/stdc++.h>
 
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

const int N = 123;

vector<int> adj[N];
int cap[N][N];

void add(int x, int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}

int flow(int s, int t, int n){
	int dist[n + 1];

	pii p[n + 1];

	queue<int> fila;

	memset(dist, -1, sizeof(dist));

	dist[s] = 0;
	p[s] = {-1, -1};

	fila.push(s);

	while(!fila.empty()){
		int x = fila.front();
		fila.pop();

		for(int y : adj[x]){
			if(cap[x][y]){
				if(dist[y] == -1){
					dist[y] = dist[x] + 1;
					
					fila.push(y);

					p[y] = {x, cap[x][y]};
				}
			}
		}
	}

	if(dist[t] == -1) return 0;

	int ret = INT_MAX;

	int k = t;

	while(p[k].first != -1){
		ret = min(ret, p[t].second);

		k = p[k].first;
	}

	k = t;

	while(p[k].first != -1){
		int from = p[k].first;
		int to = k;

		cap[from][to] = cap[to][from] = (cap[from][to] - ret);

		k = p[k].first;
	}

	return ret;
}

void init(int n){
	memset(cap, 0, sizeof cap);

	for(int i = 0; i <= n; ++i){
		adj[i].clear();
	}
}
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int n;

	int network = 0;

	while(cin >> n && n){
		cout << "Network " << ++network << endl;
		cout << "The bandwidth is ";

		int s, t, c; cin >> s >> t >> c;

		init(n);

		for(int i = 0; i < c; ++i){
			int x, y, b; cin >> x >> y >> b;

			cap[x][y] = cap[y][x] = (cap[x][y] + b);
		}

		for(int i = 0; i <= n; ++i){
			for(int j = i + 1; j <= n; ++j){
				if(cap[i][j]){
					add(i, j);
				}
			}
		}

		int curFlow, ans = 0;

		while((curFlow = flow(s, t, n)) != 0){
			ans += curFlow;
		}

		cout << ans << "." << endl << endl;
	}
 
    return 0;
}	