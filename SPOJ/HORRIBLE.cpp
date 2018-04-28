#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

ll tree[4 * MAXN];
ll lazy[4 * MAXN];
int n, c;

inline int LC(int x) {
    return (x << 1) + 1;
}

inline int RC(int x) {
    return LC(x) + 1;
}

ll query(int ql, int qr, ll L = 1, ll R = n, int node = 0) {
    if (lazy[node] != 0) {
        tree[node] += (R - L + 1) * lazy[node];

        if (L != R) {
            lazy[LC(node)] += lazy[node];
            lazy[RC(node)] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (ql > R || qr < L || L > R) return 0;

    if (ql <= L && qr >= R) {
        return tree[node];
    }

    int mid = (L + R) >> 1;

    return query(ql, qr, L, mid, LC(node)) + query(ql, qr, mid + 1, R, RC(node));
}

void updateRange(int ul, int ur, ll val, ll L = 1, ll R = n, int node = 0) {
    if (lazy[node] != 0) {
        tree[node] += (R - L + 1) * lazy[node];

        if (L != R) {
            lazy[LC(node)] += lazy[node];
            lazy[RC(node)] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (ul > R || ur < L || L > R) return;

    if (ul <= L && ur >= R) {
        tree[node] += (R - L + 1) * val;

        if (L != R) {
            lazy[LC(node)] += val;
            lazy[RC(node)] += val;
        }

        return;
    }

    int mid = (L + R) >> 1;

    updateRange(ul, ur, val, L, mid, LC(node));
    updateRange(ul, ur, val, mid + 1, R, RC(node));

    tree[node] = tree[LC(node)] + tree[RC(node)];
}

int main() {
    ios::sync_with_stdio(0);

    int t; cin >> t;

    while (t--) {
        cin >> n >> c;

        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);

        for (int i = 0; i < c; ++i) {
            ll x, p, q, v;

            cin >> x >> p >> q;

            if (x) {
                cout << query(p, q) << endl;
            } else {
                cin >> v;

                updateRange(p, q, v);
            }
        }
    }

    return 0;
}
