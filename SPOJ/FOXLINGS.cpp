#include <bits/stdc++.h>
 
#define fi first
#define se second
#define LIMIT 1000000007
#define dbg(x) cout << "variable '" << #x << << "' -> " << x << '\n';
#define oi() cout << "oi" << endl;
#define fr(a, b, c) for(int a = b, _ = c; a < _; ++a)
 
typedef unsigned long long ull;
 
using namespace std;
 
map<int, bool> visited;
map<int, vector<int> > adj;
 
void ie(int x, int y){
	adj[x].push_back(y);
	adj[y].push_back(x);
}
 
void dfs(int v){
	visited[v] = true;
 
	vector<int>::iterator i;
 
	for(i = adj[v].begin(); i != adj[v].end(); ++i){
		if(!visited[*i]){
			dfs(*i);
		}
	}
}
 
int compconex(){
	int k = 0;
	map<int, bool>::iterator i;
	for(i = visited.begin(); i != visited.end(); ++i){
		if(!i->second){
			dfs(i->first);
			k++;
		}
	}
	return k;
}
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL);
 
	int n, m; cin >> n >> m;
 
	set<int> p; //retorna ptr inserido + bool
	pair<set<int>::iterator, bool> c; //verif set insert
 
	fr(i, 0, m){
		int x, y;
		cin >> x >> y;
		//x--; y--;
		ie(x, y);
		c = p.insert(x);
		if(c.second) visited[x] = false;
		c = p.insert(y);
		if(c.second) visited[y] = false;
	}
 
	cout << compconex() + n - p.size() << endl;
	
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
 
    return 0;
} 