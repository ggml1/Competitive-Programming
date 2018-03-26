#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 1e4 + 100;

int ed[N], ei[N];

int lis(int x[], int n){
	vector<int> tail(n, 0);

	int len = 1;

	tail[0] = x[0];

	for(int i = 1; i < n; ++i){
		if(x[i] < tail[0]){
			ei[i] = 1;
			tail[0] = x[i];
		} else if(x[i] > tail[len - 1]){
			ei[i] = len + 1;
			tail[len++] = x[i];
		} else{
			int k = lower_bound(tail.begin(), tail.begin() + len, x[i]) - tail.begin();

			ei[i] = k + 1;

			tail[k] = x[i];
		}
	}

	return len;
}

int lds(int x[], int n){
	vector<int> tail(n, 0);

	int len = 1;

	tail[0] = x[n - 1];

	for(int i = n - 2; i >= 0; --i){
		if(x[i] < tail[0]){
			ed[i] = 1;
			tail[0] = x[i];
		} else if(x[i] > tail[len - 1]){
			ed[i] = len + 1;
			tail[len++] = x[i];
		} else{
			int k = lower_bound(tail.begin(), tail.begin() + len, x[i]) - tail.begin();

			ed[i] = k + 1;

			tail[k] = x[i];
		}
	}

	return len;
}

int main(){
	fast_io; cout << fixed << setprecision(10);

	int n;

	while(cin >> n){
		memset(ei, 0, sizeof ei);
		memset(ed, 0, sizeof ed);

		int x[n];

		for(int i = 0; i < n; ++i){
			cin >> x[i];
		}

		lis(x, n);
		lds(x, n);

		int ans = 1;

		for(int i = 0; i < n; ++i){
			if(ei[i] >= ed[i] || ed[i] >= ei[i]){
				int k = 2 * min(ed[i], ei[i]);

				ans = max(ans, k - 1);
			}
		}

		cout << ans << endl;
	}

	return 0;
}