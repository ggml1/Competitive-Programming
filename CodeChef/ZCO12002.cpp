#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e6 + 1;

int main(){
	ios::sync_with_stdio(0); cout << fixed << setprecision(10);

	int n, x, y; cin >> n >> x >> y;

	pii con[n];

	vector<int> wormgo(x), wormleave(y);

	for(int i = 0; i < n; ++i){
		cin >> con[i].first >> con[i].second;
	}

	for(int i = 0; i < x; ++i){
		cin >> wormgo[i];
	}

	for(int i = 0; i < y; ++i){
		cin >> wormleave[i];
	}

	sort(con, con + n);
	sort(wormgo.begin(), wormgo.end());
	sort(wormleave.begin(), wormleave.end());

	int j = 0;

	int ans = INT_MAX;

	for(int i = 0; i < n; ++i){
		int curS = con[i].first;
		int curE = con[i].second;

		while(j < x && wormgo[j] <= curS){
			++j;
		}

		--j;

		int b = wormgo[j];

		int k = lower_bound(wormleave.begin(), wormleave.end(), curE) - wormleave.begin();=

		if(k == y) continue;


		ans = min(ans, wormleave[k] - b + 1);
	}

	cout << ans << endl;

	return 0;
}