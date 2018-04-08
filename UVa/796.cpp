#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

vector<int> adj[N];
vector<pair<int, int>> articE;
int dfsl[N], dfsn[N], par[N];
int cnt;

void init() {
    for (int i = 0; i < N; ++i) {
        dfsl[i] = 0;
        dfsn[i] = par[i] = -1;

        adj[i].clear();
    }

    articE.clear();
    cnt = 0;
}

void dfs(int v) {
    dfsn[v] = dfsl[v] = ++cnt;

    for (int u : adj[v]) {
        if (dfsn[u] == -1) {
            par[u] = v;

            dfs(u);

            if (dfsl[u] > dfsn[v]) {
                articE.push_back({min(u, v), max(u, v)});
            }

            dfsl[v] = min(dfsl[v], dfsl[u]);
        } else if (u != par[v]) {
            dfsl[v] = min(dfsl[v], dfsn[u]);
        }
    }
}

int main() {
    int sv;

    while (scanf("%d", &sv) != EOF) {
        init();

        for (int i = 0; i < sv; ++i) {
            int s, c; scanf("%d (%d)", &s, &c);

            for (int j = 0; j < c; ++j) {
                int t; scanf("%d", &t);

                adj[s].push_back(t);
            }
        }

        for (int i = 0; i < sv; ++i) {
            if (dfsn[i] == -1) {
                dfs(i);
            }
        }

        printf("%d critical links\n", articE.size());

        sort(articE.begin(), articE.end());
        
        for (auto x : articE) {
            printf("%d - %d\n", x.first, x.second);
        }

        printf("\n");
    }

    return 0;
}