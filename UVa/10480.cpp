#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 55;
const int SOURCE = 1, SINK = 2;

struct Edge{
    int from, to;
    ll cap;

    Edge(int f = 0, int t = 0, ll c = 0) :
        from(f), to(t), cap(c){}
};

vector<Edge> edges;
vector<int> adj[N];
int p[N], d[N];
bool vis[N];
int n, m;

void init(int n){
    for(int i = 0; i <= n; ++i){
        adj[i].clear();
    }

    edges.clear();
    memset(vis, 0, sizeof(vis));
}

void add(int from, int to, ll cap){
    adj[from].push_back(edges.size());
    edges.emplace_back(from, to, cap);

    adj[to].push_back(edges.size());
    edges.emplace_back(to, from, cap);
}

ll augment(){
    memset(d, -1, sizeof(d));
    memset(p, -1, sizeof(p));

    d[SOURCE] = 0;

    queue<int> q;

    q.push(SOURCE);

    while(!q.empty()){
        int from = q.front();
        q.pop();

        for(int ID : adj[from]){
            Edge cur = edges[ID];

            if(d[cur.to] == -1 && cur.cap > 0){
                p[cur.to] = ID;
                d[cur.to] = 1;
                q.push(cur.to);
            }
        }
    }

    if(d[SINK] == -1) return 0;

    int k = SINK;

    ll flow = LONG_MAX;

    while(p[k] != -1){
        flow = min(flow, edges[p[k]].cap);

        k = edges[p[k]].from;
    }

    k = SINK;

    while(p[k] != -1){
        int ID = p[k];

        edges[ID].cap -= flow;
        edges[ID ^ 1].cap += flow;

        k = edges[ID].from;
    }

    return flow;
}

ll maxflow(){
    int flow = 0;
    int curFlow = 0;

    while((curFlow = augment()) != 0){
        flow += curFlow;
    }

    return flow;
}

void dfs(int cur){
    vis[cur] = 1;

    for(int ID : adj[cur]){
        Edge x = edges[ID];

        if(!vis[x.to] && x.cap > 0){
            dfs(x.to);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    while(cin >> n >> m && (n || m)){
        init(n);

        for(int i = 0; i < m; ++i){
            int a, b; ll c; cin >> a >> b >> c;

            add(a, b, c);
        }

        maxflow();

        dfs(SOURCE);

        for(Edge x : edges){
            if(x.cap == 0 && vis[x.from] && !vis[x.to]){
                cout << x.from << ' ' << x.to << endl;
            }
        }

        cout << endl;
    }

    return 0;
}