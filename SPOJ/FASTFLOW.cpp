#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge{
    ll to, flow, cap;

    Edge(int t = 0, ll f = 0, ll c = 0) :
    	to(t), flow(f), cap(c) {}
};

const int inf = 1000 * 1000 * 1000;
const int MAXN = 5050;

int n, m;
vector<Edge> edges;
int start[MAXN];
vector<int> adj[MAXN];
ll flow = 0;
int d[MAXN];
int lim;
int s, t;

void add(int a, int b, ll c){                                                                           
    Edge ed1(b, 0, c), ed2(a, 0, c);

    adj[a].push_back(edges.size());
    edges.push_back(ed1);

    adj[b].push_back(edges.size());
    edges.push_back(ed2);
}

bool bfs(){
    memset(d, -1, sizeof d);

    d[s] = 0;

    queue<int> q;

    q.push(s);

    while(!q.empty() && d[t] == -1){
        int cur = q.front();
        q.pop();

        for(int id : adj[cur]){
            int to = edges[id].to;

            if(d[to] == -1 && edges[id].cap - edges[id].flow >= lim){
                d[to] = d[cur] + 1;
                q.push(to);
            }
        }
    }

    return d[t] != -1;
}

bool dfs(int on){
    if(lim == 0) return false;

    if(on == t) return true;

    for(; start[on] < adj[on].size(); start[on]++){
        int id = adj[on][start[on]];
        int to = edges[id].to;

        if(d[to] == d[on] + 1 && edges[id].cap - edges[id].flow >= lim){
            if(dfs(to)){
                edges[id].flow += lim;
                edges[id ^ 1].flow -= lim;
                return true;
            }               
        }
    }

    return false;
}

void dinic(){
	lim = (1 << 30);

	while(lim >= 1){
		if(!bfs()){
			lim >>= 1;
			continue;
		}

		memset(start, 0, sizeof start);

		while(dfs(s) == 1){
			flow += lim;
		}
	}
}

int main(){
    scanf("%d %d", &n, &m);
    
    s = 1; t = n;

    for(int i = 1; i <= m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }

    dinic();

    printf("%lld\n", flow);

    return 0;
}