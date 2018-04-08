#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

vector<int> adj[N];
bool seen[N];
list<int> topo;

void init() {
    for (int i = 0; i < N; ++i) {
        seen[i] = false;
        adj[i].clear();
    }

    topo.clear();
}

void dfs(int v) {
    seen[v] = 1;

    for (int u : adj[v]) {
        if (!seen[u]) {
            dfs(u);
        }
    }

    topo.push_front(v);
}

int main() {
    int t; scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, m; cin >> n >> m;

        init();

        for (int i = 0; i < m; ++i) {
            int a, b; scanf("%d %d", &a, &b);

            adj[a].push_back(b);
        }

        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                dfs(i);
            }
        }

        memset(seen, 0, sizeof seen);

        int ans = 0;

        for (int x : topo) {
            if (!seen[x]) {
                dfs(x);
                ++ans;
            }
        }
        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}