#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 5;
const int MAXC = 1e6 + 5;

bool sieve[MAXC];
int n, q, t;
int tree[4 * MAXN];
int lazy[4 * MAXN];
int arr[MAXN];

inline int LC(int x) {
    return (x << 1) + 1;
}

inline int RC(int x) {
    return LC(x) + 1;
}

void erat() {
    sieve[1] = sieve[0] = 1;

    for (int i = 2; i < MAXC; ++i) {
        if (!sieve[i]) {
            for (int j = i + i; j < MAXC; j += i) {
                sieve[j] = 1;
            }
        }
    }
}

void build(int L = 1, int R = n, int node = 0) {
    if (L > R) return;

    if (L == R) {
        tree[node] = !sieve[arr[L]];
    } else {
        int mid = (L + R) >> 1;

        build(L, mid, LC(node));
        build(mid + 1, R, RC(node));

        tree[node] = tree[LC(node)] + tree[RC(node)];
    }
}

void update(int ul, int ur, int val, int L = 1, int R = n, int node = 0) {
    if (lazy[node] != -1) {
        tree[node] = lazy[node] * (R - L + 1);

        if (L != R) {
            lazy[LC(node)] = lazy[node];
            lazy[RC(node)] = lazy[node];
        }

        lazy[node] = -1;
    }

    if (ul > R || ur < L || L > R) return;

    if (ul <= L && ur >= R) {
        tree[node] = val * (R - L + 1);

        if (L != R) {
            lazy[LC(node)] = val;
            lazy[RC(node)] = val;
        }

        return;
    }

    int mid = (L + R) >> 1;

    update(ul, ur, val, L, mid, LC(node));
    update(ul, ur, val, mid + 1, R, RC(node));

    tree[node] = tree[LC(node)] + tree[RC(node)];
}

int query(int ql, int qr, int L = 1, int R = n, int node = 0) {
    if (lazy[node] != -1) {
        tree[node] = lazy[node] * (R - L + 1);

        if (L != R) {
            lazy[LC(node)] = lazy[node];
            lazy[RC(node)] = lazy[node];
        }

        lazy[node] = -1;
    }

    if (ql > R || qr < L || L > R) return 0;

    if (ql <= L && qr >= R) {
        return tree[node];
    }

    int mid = (L + R) >> 1;

    return query(ql, qr, L, mid, LC(node)) + query(ql, qr, mid + 1, R, RC(node));
}

int main() {
    ios::sync_with_stdio(0);

    erat();

    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":" << endl;
        cin >> n >> q;

        memset(lazy, -1, sizeof lazy);
        memset(tree, 0, sizeof tree);

        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        build();

        for (int i = 0; i < q; ++i) {
            int p, x, y, v;
            cin >> p >> x >> y;

            if (p) {
                cout << query(x, y) << endl;
            } else {
                cin >> v;
                update(x, y, !sieve[v]);
            }
        }
    }

    return 0;
}
