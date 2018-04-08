#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 5;

vector<int> adj[N];
int dfsl[N], dfsn[N], par[N];
bool is[N];
int cnt;
int root, rootChildren;

void init() {
	memset(dfsl, 0, sizeof dfsl);
	memset(par, 0, sizeof par);
	memset(is, 0, sizeof is);
	memset(dfsn, -1, sizeof dfsn);

	for (int i = 0; i < N; ++i) {
		adj[i].clear();
	}

	cnt = 0;
}

void dfs(int v) {
	dfsn[v] = dfsl[v] = cnt++;

	for (int u : adj[v]) {
		if (dfsn[u] == -1) {
			par[u] = v;

			if(v == root){
				rootChildren++;
			}

			dfs(u);

			if (v != root && dfsl[u] >= dfsn[v]) {
				is[v] = 1;
			}

			dfsl[v] = min(dfsl[v], dfsl[u]);
		} else if (u != par[v]) {
			dfsl[v] = min(dfsl[v], dfsn[u]);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);

	int n;

	int cases = 0;

	while (cin >> n && n) {
		++cases;

		init();

		cin.ignore();

		string s;

		while (getline(cin, s) && s.compare("0") != 0) {
			stringstream in(s);

			int u; in >> u;

			int v;

			while (in >> v) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (dfsn[i] == -1) {
				root = i;
				rootChildren = 0;

				dfs(i);

				is[root] = (rootChildren > 1);
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; ++i) {
			if (is[i]) {
				++ans;
			}
		}

		cout << ans << endl;
	}



	return 0;
}