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
const int ms = int(1e4) + 5;

ll dist[ms];

int dijkstra(int st, int en, vector<pii> adj[]){
	memset(dist, 0x3f3f3f3f, sizeof(dist));

	dist[st] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> heap;

	heap.push({0, st});

	while(!heap.empty()){
		pii x = heap.top();
		heap.pop();

		int vx = x.se;
		int w = x.fi;

		if(w > dist[vx]) continue;

		for(auto k : adj[vx]){
			int aa = k.se;
			int wa = k.fi;

			if(dist[aa] > dist[vx] + wa){
				dist[aa] = dist[vx] + wa;
				heap.push({dist[aa], aa});
			}
		}
	}

	return dist[en];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(4);

    int n; cin >> n;

    while(n--){
    	int v, k; cin >> v >> k;

    	vector<pii> adj[ms];

    	for(int i = 0; i < k; ++i){
    		int a, b, w; cin >> a >> b >> w;
    		adj[a].push_back({w, b});
    	}

    	int x, y; cin >> x >> y;

    	ll z = dijkstra(x, y, adj);

    	if(z == inf) cout << "NO" << endl;
    	else cout << z << endl;
    }

    return 0;
}