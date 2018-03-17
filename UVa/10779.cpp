#include <bits/stdc++.h>

using namespace std;

struct Edges{
    int from, to, cap;

    Edges(int f = 0, int t = 0, int c = 0) :
        from(f), to(t), cap(c) {}
};

const int MAXN = 100;

vector<int> adj[MAXN];
vector<Edges> edge;
int q[MAXN][MAXN];
int p[MAXN], d[MAXN];

void init(){
    for(int i = 0; i < MAXN; ++i){
        adj[i].clear();
    }

    edge.clear();

    memset(q, 0, sizeof q);
}

void add(int from, int to, int cap){
    Edges a(from, to, cap);
    Edges b(to, from, 0);

    adj[from].push_back(edge.size());
    edge.push_back(a);

    adj[to].push_back(edge.size());
    edge.push_back(b);
}

int augment(int s, int t){
    queue<int> q;

    memset(d, 0, sizeof d);
    memset(p, -1, sizeof p);

    d[s] = 1;

    q.push(s);

    while(!q.empty()){
        int from = q.front();
        q.pop();

        for(int id : adj[from]){
            int to = edge[id].to;

            if(!d[to] && edge[id].cap > 0){
                p[to] = id;
                d[to] = 1;
                q.push(to);
            }
        }
    }

    if(!d[t]) return 0;

    int k = t;
    int flow = INT_MAX;

    while(p[k] != -1){
        flow = min(flow, edge[p[k]].cap);

        k = edge[p[k]].from;
    }

    k = t;

    while(p[k] != -1){
        edge[p[k]].cap -= flow;
        edge[p[k] ^ 1].cap += flow;

        k = edge[p[k]].from;
    }

    return flow;
}

int maxFlow(int source, int sink){
    int flow = 0;
    int cur = 0;

    while((cur = augment(source, sink)) != 0){
        flow += cur;
    }

    return flow;
}

int main(){
    ios::sync_with_stdio(0);

    int t; cin >> t;

    for(int caso = 1; caso <= t; ++caso){
        init();

        int n, m; cin >> n >> m;

        int source = 0, sink = n + m + 5;

        for(int i = 1; i <= n; ++i){
            int k; cin >> k;

            for(int j = 1; j <= k; ++j){
                int x; cin >> x;

                q[i][x]++;
            }
        }

        for(int i = 1; i <= m; ++i){
            add(source, n + i, q[1][i]);
            add(n + i, sink, 1);
        }

        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(q[i][j]){
                    add(i, n + j, q[i][j] - 1);
                } else{
                    add(n + j, i, 1);
                }
            }
        }

        cout << "Case #" << caso << ": " << maxFlow(source, sink) << endl;
    }

    return 0;
}