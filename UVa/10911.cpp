#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

const int ms = 17;
const double inf = 1e18;

double memo[ms][1 << ms];
double dist[ms][ms];

double distx(pair<double, double> x, pair<double, double> y){
	return sqrt((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second));
}

double dp(int done, int mask, int mp, int mm){
	if(mask == mm) return 0;

	if(memo[done][mask] != inf) return memo[done][mask];

	for(int i = 0; i < 2*mp; ++i){
		for(int j = i + 1; j < 2*mp; ++j){
			if(!(mask & (1 << i)) && !(mask & (1 << j))){
				memo[done][mask] = min(memo[done][mask], dp(done + 1, (mask | (1 << i)) | (1 << j), mp, mm) + dist[i][j]);
			}
		}
	}

	return memo[done][mask];
}

int main(){
	fast_io; cout << fixed << setprecision(2);

	int n; cin >> n;

	int kse = 0;

	while(n != 0){
		++kse;

		int k = (n << 1);

		pair<double, double> x[k];

		for(int i = 0; i < k; ++i){
			string name; cin >> name;

			cin >> x[i].first >> x[i].second;
		}

		for(int i = 0; i < k; ++i){
			for(int j = i + 1; j < k; ++j){
				dist[i][j] = dist[j][i] = distx(x[i], x[j]);
			}
		}

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < (1 << k); ++j){
				memo[i][j] = inf;
			}
		}

		cout << "Case " << kse << ": " << dp(0, 0, n, (1 << k) - 1) << endl;

		cin >> n;
	}

    return 0;
}