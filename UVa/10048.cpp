#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oi() cout << "oi\n";
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int ms = 1234;
const ll inf = 123456789;

ll graph[ms][ms];
ll dist[ms][ms];
ll maxes[ms][ms];

void floyd(int c){
	for(int k = 1; k <= c; ++k){
		for(int i = 1; i <= c; ++i){
			for(int j = 1; j <= c; ++j){
				dist[i][j] = min(dist[i][j], max(dist[k][j], dist[i][k]));
				dist[j][i] = min(dist[i][j], max(dist[k][j], dist[i][k]));
			}
		}
	}
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int c, s, q; cin >> c >> s >> q;

    int kse = 0;

    while(c || s || q){
    	++kse;
    	if(kse != 1) cout << endl;

    	for(int i = 1; i <= c; ++i){
    		for(int j = 1; j <= c; ++j){
    			graph[i][j] = inf;
    			dist[i][j] = inf;
    			maxes[i][j] = inf;
    		}
    	}

    	for(int i = 0; i < s; ++i){
    		int a, b, w; cin >> a >> b >> w;
    		graph[a][b] = w;
    		graph[b][a] = w;
    		dist[a][b] = w;
    		dist[b][a] = w;
    	}

    	floyd(c);

    	cout << "Case #" << kse << "\n";

    	for(int i = 0; i < q; ++i){
    		int a, b; cin >> a >> b;
    		if(dist[a][b] == inf) cout << "no path\n";
    		else cout << dist[a][b] << endl;
    	}

    	cin >> c >> s >> q;
    }

    return 0;
}