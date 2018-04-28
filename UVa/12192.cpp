#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 502;

vector<int> mat[MAXN];

int main() {
	int n, m;

	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
        for (int i = 0; i < n; ++i) {
            mat[i].resize(m);
        }

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &mat[i][j]);
			}
		}

		int q; scanf("%d", &q);

		for (int i = 0; i < q; ++i) {
			int l, u; scanf("%d%d", &l, &u);

			int ans = 0;

			for (int j = 0; j < n; ++j) {
				if (mat[j][m - 1] < l) continue;

			 	int p = lower_bound(mat[j].begin(), mat[j].end(), l) - mat[j].begin();

				for (int k = 0; j + k < n && p + k < m; k++) {
					if (mat[j + k][p + k] <= u) {
						ans = max(ans, k + 1);
					} else break;
				}
			}

			printf("%d\n", ans);
		}

		printf("-\n");
	}

    return 0;
}
