#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 400;

bool bip;
vector<int> adj[N];
int color[N];
int cnt1, cnt2;

void init() {
	for (int i = 0; i < N; ++i) {
		color[i] = -1;
		adj[i].clear();
	}
}

void dfs(int v) {
	if (color[v] == 1) cnt1++;
	else cnt2++;

	for (int u : adj[v]) {
		if (color[u] == -1) {
			color[u] = (color[v] ^ 1);
			dfs(u);
		} else {
			if (color[u] == color[v]) {
				bip = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);

	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;

		init();

		for (int i = 0; i < m; ++i) {
			int u, v; cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = 0;

		bip = 1;

		for (int i = 0; i < n && bip; ++i) {
			if (color[i] == -1) {
				cnt1 = 0, cnt2 = 0;

				color[i] = 1;

				dfs(i);

				ans += max(1, min(cnt1, cnt2));
			}
		}

		if (!bip) cout << -1 << endl;
		else cout << ans << endl;
	}	

	return 0;
}