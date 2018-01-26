#include <bits/stdc++.h>

using namespace std;

int a[123], n;

int solve(){
	vector<int> lis(n, 1);

	for(int i = 1; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(a[i] > a[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
			}
		}
	}

	int ret = -1;

	for(int i = 0; i < n; ++i){
		ret = max(ret, lis[i]);
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(0);

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	cout << solve() << endl;

	return 0;
}