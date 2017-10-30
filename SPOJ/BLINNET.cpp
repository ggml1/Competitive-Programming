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
int parent[ms];

int find(int x){
	while(parent[x] != x){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void unite(int x, int y){
	int p = find(x);
	int q = find(y);

	parent[p] = parent[q];
}

ll kruskal(vector<pair<int, pii>> edges, int size, int cities){

	for(int i = 0; i <= cities; ++i){
		parent[i] = i;
	}

	ll mncost = 0;

	for(int i = 0; i < size; ++i){
		int x1 = edges[i].se.fi;
		int x2 = edges[i].se.se;
		int cc = edges[i].fi;

		if(find(x1) != find(x2)){
			mncost += cc;
			unite(x1, x2);
		}
	}

	return mncost;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(4);

    int n; cin >> n;

    while(n--){
    	int ct; cin >> ct;

    	int tt = 0;

    	vector<pair<int, pii>> edges;

    	for(int i = 1; i <= ct; ++i){
    		string name; cin >> name;
    		int x; cin >> x;
    		tt += x;
    		for(int j = 0; j < x; ++j){
    			int k, w; cin >> k >> w;
    			edges.push_back({w, {i, k}});
    		}
    	}

    	sort(all(edges));

    	cout << kruskal(edges, tt, ct) << endl;
    }

    return 0;
}