#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

char mat[N][N];
bool seen[N][N];
int n;

int mx[] = { 0, 0, 1, -1 };
int my[] = { 1, -1, 0, 0 };

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void init() {
    memset(seen, 0, sizeof seen);
}

void dfs(int u, int v) {
    seen[u][v] = 1;

    for (int i = 0; i < 4; ++i) {
        int tu = u + mx[i];
        int tv = v + my[i];

        if (valid(tu, tv) && mat[tu][tv] != '.' && !seen[tu][tv]) {
            dfs(tu, tv);
        }
    }
}

int main() {
    int t; scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        init();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf(" %c", &mat[i][j]);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'x') {
                    if (!seen[i][j]) {
                        ++ans;
                        dfs(i, j);
                    }
                }
            }
        }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}