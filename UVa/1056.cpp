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
const int ms = 123;

ll dist[ms][ms];
ll ans;

void floyd(int p){
	for(int k = 1; k <= p; ++k){
		for(int i = 1; i <= p; ++i){
			for(int j = 1; j <= p; ++j){
				if(i == j) continue;
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					dist[j][i] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void showmap(int p){
	for(int i = 1; i <= p; ++i){
		for(int j = 1; j <= p; ++j){
			if(dist[i][j] == inf) cout << "inf" << ' ';
			else cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

bool checkDisc(int p){
	floyd(p);

	for(int i = 1; i <= p; ++i){
		for(int j = 1; j <= p; ++j){
			if(i == j) continue;
			if(dist[i][j] == inf) return 0;
			ans = max(ans, dist[i][j]);
		}
	}

	return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout << fixed; cout << setprecision(4);

    int p, r; cin >> p >> r;
    int kse = 0;

    while(p || r){
    	++kse;

    	map<string, int> namePos;
        map<int, string> posName;
      	
      	for(int i = 0; i <= p; ++i){
      		for(int j = 0; j <= p; ++j){
      			dist[i][j] = inf;
      		}
      	}
    
        int count = 0;

        ans = 0;
    
        for(int i = 0; i < r; ++i){
        	string a, b; cin >> a >> b;
        	if(!namePos[a]) namePos[a] = ++count;
        	if(!namePos[b]) namePos[b] = ++count;
        	int u = namePos[a], v = namePos[b];
        	dist[u][v] = dist[v][u] = 1;
        }
    
        if(!checkDisc(p)) cout << "Network " << kse << ": DISCONNECTED" << endl;
        else{
        	//showmap(count);
        	cout << "Network " << kse << ": ";
        	cout << ans << endl;
        }
    	
    	cout << endl;
        cin >> p >> r;
    }

    return 0;
}