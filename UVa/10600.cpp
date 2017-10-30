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
bool flagged[ms];

bool compare(string x, string y){
	string a = x;
	string b = y;
	for(int i = 0; i < a.size(); ++i){
		bool found = 0;
		for(int j = 0; j < b.size(); ++j){
			if(a[i] == b[j]){
				b[j] = '.';
				found = 1;
				break;
			}
		}
		if(!found) return 0;
	}
	return 1;
}

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

ll kruskal(vector<pair<int, pii>> edges, int size, int cities, string& used1){

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
			used1 += to_string(i);
		}
	}

	return mncost;
}

ll kruskal2(vector<pair<int, pii>> edges, int size, int cities, string& used2){

	for(int i = 0; i <= cities; ++i){
		parent[i] = i;
	}

	ll mncost = 0;

	for(int i = 0; i < size; ++i){
		if(!flagged[i]){
			int x1 = edges[i].se.fi;
			int x2 = edges[i].se.se;
			int cc = edges[i].fi;

			if(find(x1) != find(x2)){
				mncost += cc;
				unite(x1, x2);
				used2 += to_string(i);
			}
		}
	}

	return mncost;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(4);

    int n; cin >> n;

    while(n--){
    	int schools, cnn; cin >> schools >> cnn;

    	vector<pair<int, pii>> edges;

		for(int j = 0; j < cnn; ++j){
			int a, b, w; cin >> a >> b >> w;
			edges.push_back({w, {a, b}});
		}

    	sort(all(edges));

    	memset(flagged, 0, sizeof(flagged));

    	string used1;

    	int ans1 = kruskal(edges, cnn, schools, used1);

    	int ans2 = INT_MAX;

    	for(int i = 0; i < cnn; ++i){
    		flagged[i] = true;
    		string used2;
    		int u = kruskal2(edges, cnn, schools, used2);
    		if(!compare(used1, used2) && u >= ans1) ans2 = min(ans2, u);
    		flagged[i] = false;
    	}

    	cout << ans1 << ' ' << ans2 << endl;
    }

    return 0;
}