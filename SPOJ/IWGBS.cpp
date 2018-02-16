#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, map<int, string>> memo;
int need[10];

string bigger(string a, string b){
	int na = a.size();
	int nb = b.size();

	if(na > nb) return a;
	if(nb > na) return b;

	for(int i = 0; i < na; ++i){
		if(a[i] > b[i]) return a;
		else if(b[i] > a[i]) return b;
	}

	return a;
}

string dp(string has, int len, int money){
	if(money <= 0){
		return has;
	}

	if(memo.count(money) && memo[money].count(len) != 0) return memo[money][len];

	for(int i = 9; i >= 1; --i){
		if(money - need[i] >= 0){
			memo[money][len] = bigger(memo[money][len], 
									  dp(has + to_string(i), len + 1, money - need[i]));
		}
	}

	return memo[money][len];
}

long long kruskal(vector<int> edges){
	for(auto k : edges){
		if(find(k.se) != find(k.fi)){
			
		}
	}
}

void dijkstra(int beg){
	priority_queue<pii, vector<pii>, greater<pii>> heap;

	heap.push({0, beg});

	dist[beg] = 0;

	while(!heap.empty()){
		pii k = heap.top();
		heap.pop();

		if(k.fi > dist[k.se]) continue;

		for(auto x : adj[k.se]){
			int to = x.se;

			if(dist[to] > dist[k.se] + x.fi){
				dist[to] = dist[k.se] + x.fi;
				heap.push({dist[to], to});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);

	int money; cin >> money;

	bool ok = 0;

	for(int i = 1; i <= 9; ++i){
		cin >> need[i];

		if(need[i] <= money) ok = 1;
	}

	if(!ok) return puts("-1");

	cout << dp("", 0, money) << endl;
	
	return 0;
}