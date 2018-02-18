#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

void update(int key, int n, int bit[]){
	while(key <= n){
		bit[key]++;

		key += key & (-key);
	}
}

ll sum(int idx, int bit[]){
	ll ret = 0;

	while(idx > 0){
		ret += bit[idx];

		idx -= idx & -idx;
	}

	return ret;
}

int main(){

	int t; scanf("%d", &t);

	while(t--){
		int n; scanf("%d", &n);

		int arr[n];

		int maxsize = 1;

		for(int i = 0; i < n; ++i){
			scanf("%d", &arr[i]);

			maxsize = max(maxsize, arr[i]);
		}

		int bit[maxsize + 1];

		memset(bit, 0, sizeof(bit));

		ll ans = 0;

		for(int i = n - 1; i >= 0; --i){
			ans += sum(arr[i] - 1, bit);

			update(arr[i], maxsize, bit);
		}

		printf("%lld\n", ans);
	}

	return 0;
} 