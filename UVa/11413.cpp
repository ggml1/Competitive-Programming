#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1001;

ll v[MAXN];
int n, m;

bool can(ll mid) {
	ll cnt = 1, cap = 0;

	for (int i = 0; i < n; ++i) {
		if (v[i] > mid) return 0;

		if (cap + v[i] > mid) {
			cnt++;
			if (cnt > m) return 0;
			cap = v[i];
		} else {
			cap += v[i];
		}
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(nullptr);

	while (cin >> n >> m) {
		ll s = 0;

		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			s += v[i];
		}

		ll lo = 0, hi = s + 1, best = 0;

		while (lo <= hi) {
			ll mid = (lo + hi) >> 1;

			if (can(mid)) {
				best = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		cout << best << endl;
	}

    return 0;
}
