#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int phi[MAXN];
int depth[MAXN];
int pref[MAXN][22];

void erat() {
    phi[1] = 1; phi[0] = 0;

    memset(pref, 0, sizeof pref);

    for (int i = 2; i < MAXN; ++i) {
        phi[i] = i;
        depth[i] = -1;
    }

    for (int i = 2; i < MAXN; ++i) {
        if (phi[i] == i) {
            phi[i] = i - 1;
            for (int j = i + i; j < MAXN; j += i) {
                phi[j] = ((phi[j]) / i ) * (i - 1);
            }
        }
    }

    depth[1] = 0;
    depth[2] = 1;

    pref[1][0]++;
    pref[2][1]++;

    for (int i = 3; i < MAXN; ++i) {
        int j = i;
        int cnt = 0;
        while (depth[j] == -1) {
            j = phi[j];
            ++cnt;
        }
        depth[i] = depth[j] + cnt;

        if (depth[i] <= 20) pref[i][depth[i]]++;
    }

    for (int i = 0; i < 22; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            pref[j][i] += pref[j - 1][i];
        }
    }
}



int main() {
    ios::sync_with_stdio(0);

    erat();

    int t; cin >> t;

    while (t--) {
        int m, n, k; cin >> m >> n >> k;

        cout << pref[n][k] - pref[m - 1][k] << endl;
    }

    return 0;
}
