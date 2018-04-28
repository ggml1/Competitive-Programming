#include <bits/stdc++.h>

using namespace std;

const int N = 120;

int dfsl[N], dfsn[N], vis[N];
int done[N];
set<int> adj[N];
vector<int> st;
vector<vector<int>> scc;
int cnt, dfsCnt;
map<string, int> id;
map<int, string> name;
vector<string> ans;

void add(int x, int y) {
    adj[x].insert(y);
}

void init() {
    for (int i = 0; i < N; ++i) {
        adj[i].clear();
        dfsl[i] = vis[i] = done[i] = 0;
        dfsn[i] = -1;
    }
    cnt = 0;
    dfsCnt = 0;
    scc.clear();
    id.clear();
    name.clear();
    st.clear();
}

void dfs(int on) {
    dfsn[on] = dfsl[on] = dfsCnt++;
    st.push_back(on);
    vis[on] = 1;
    for (int nxt : adj[on]) {
        if (dfsn[nxt] == -1) {
            dfs(nxt);
        }
        if (vis[nxt]) {
            dfsl[on] = min(dfsl[on], dfsl[nxt]);
        }
    }

    if (dfsl[on] == dfsn[on]) {
        vector<int> cur;
        while (1) {
            int x = st.back(); st.pop_back();
            vis[x] = 0;
            cur.push_back(x);
            if (x == on) break;
        }
        scc.push_back(cur);
    }
}

void dfs2(int v) {
    if (!done[v]) {
        ans.push_back(name[v]);
        done[v] = 1;
        for (int u : adj[v]) {
            dfs2(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    int n;

    while (cin >> n && n) {
        init(); cin.ignore();

        for (int i = 0; i < n; ++i) {
            string s; getline(cin, s);

            stringstream a(s);
            string u, v; a >> u;

            if (!id.count(u)) {
                id[u] = ++cnt;
                name[id[u]] = u;
            }

            while (a >> v) {
                if (!id.count(v)) {
                    id[v] = ++cnt;
                    name[id[v]] = v;
                }

                add(id[u], id[v]);
            }
        }

        for (int i = 1; i <= cnt; ++i) {
            if (dfsn[i] == -1) {
                dfs(i);
            }
        }

        ans.clear();

        for (auto x : scc) {
            if (x.size() > 1) {
                dfs2(x[0]);
            }
        }

        sort(ans.begin(), ans.end());

        cout << ans.size() << endl;

        for (string s : ans) {
            cout << s;

            if (s == ans.back()) cout << endl;
            else cout << ' ';
        }
    }

    return 0;
}
