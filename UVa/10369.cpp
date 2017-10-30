#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oi() cout << "oi\n";
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 123456789;
const int ms = 650;

double dist[ms][ms];

double calc(pii x, pii y){
	return sqrt((x.fi-y.fi)*(x.fi-y.fi) + (x.se-y.se)*(x.se-y.se));
}

bool comp(const pii &a, const pii &b){
	return calc(a, make_pair(0, 0)) < calc(b, make_pair(0, 0));
}

void floyd(int p){
	for(int k = 0; k < p; ++k){
		for(int i = 0; i < p; ++i){
			for(int j = 0; j < p; ++j){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void dfs(int v, bool vis[], vector<int> adj[]){
	vis[v] = 1;

	for(int i = 0; i < adj[v].size(); ++i){
		int k = adj[v][i];
		if(!vis[k]) dfs(k, vis, adj);
	}
}

int find(int x, int parents[]){
	while(parents[x] != x){
		parents[x] = parents[parents[x]];
		x = parents[x];
	}
	return x;
}

void unite(int x, int y, int parents[]){
	int px = find(x, parents);
	int py = find(y, parents);
	parents[px] = parents[py];
}

bool check(double D, int p, int s){
	int parents[p];

	for(int i = 0; i < p; ++i){
		parents[i] = i;
	}

	int tt = 0;

	for(int i = 0; i < p; ++i){
		for(int j = i+1; j < p; ++j){
			if(find(i, parents) != find(j, parents)){
				if(dist[i][j] <= D){
					unite(i, j, parents);
					tt++;
				}
			}
		}
	}

	if(p - tt <= s) return 1;

	return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(2);

    int n; cin >> n;

    while(n--){
    	int s, p; cin >> s >> p;

    	pii points[p];

    	for(int i = 0; i < p; ++i){
    		cin >> points[i].fi >> points[i].se;
    	}

    	sort(points, points + p, comp);

    	for(int i = 0; i < p; ++i){
    		for(int j = 0; j < p; ++j){
    			dist[i][j] = calc(points[i], points[j]);
    		}
    	}

    	vector<double> values;

		for(int i = 0; i < p; ++i){
    		for(int j = i+1; j < p; ++j){
    			values.push_back(dist[i][j]);
    		}
    	}

    	sort(all(values));

    	for(int j = 0; j < values.size(); ++j){
    		if(check(values[j], p, s)){
    			cout << values[j] << endl;
    			break;
    		}
    	}
    }

    return 0;
}