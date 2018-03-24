#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e7 + 500;

ll q[N], x[N];

int main(){
	// ios::sync_with_stdio(0); cout << fixed << setprecision(10);

	int n, m; scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i){
		scanf("%lld", &x[i]);
	}

	sort(x, x + n);

	queue<ll> q1, q2;
	
	for(int i = n - 1; i >= 0; --i){
		q1.push(x[i]);
	}

	memset(q, 0, sizeof q);

	int cnt = 0;

	for(int i = 0; i < m; ++i){
		int qx; scanf("%d", &qx);

		if(q[qx - 1]) printf("%lld\n", q[qx - 1]);
		else{
			while(cnt < qx){
				ll x;

				if(!q1.empty()){
					if(q1.front() >= q2.front()){
						x = q1.front();
						q1.pop();
					} else{
						x = q2.front();
						q2.pop();
					}
				} else{
					x = q2.front();
					q2.pop();
				}

				q[cnt] = x;

				x >>= 1;

				if(x) q2.push(x);

				++cnt;
			}

			printf("%lld\n", q[qx - 1]);
		}
	}

	return 0;
}