#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int main(){
 
	int n, m; scanf("%d%d", &n, &m);

	ll x[n];

	for(int i = 0; i < n; ++i){
		scanf("%lld", &x[i]);
	}

	int i = 0, j = 1;

	ll cur = x[0] + x[1];

	ll best = 0;

	while(j < n && i <= j){
		if(cur > m){
			cur -= x[i];
			++i;
		} else if(cur == m){
			best = m;
			break;
		} else{
			best = max(best, cur);

			++j;

			if(j < n) cur += x[j];
		}
	}

	printf("%lld\n", best);
 
	return 0;
}  