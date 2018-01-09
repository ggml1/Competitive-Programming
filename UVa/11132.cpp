#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int sum(long long int x){
	if(x < 10) return x;
	else{
		int ret = 0;

		while(x){
			ret += x%10;
			x /= 10;
		}

		return sum(ret);
	}
}

int main(){
	fast_io;

	long long int t; cin >> t;

	while(t){
		cout << sum(t) << endl;

		cin >> t;
	}

    return 0;
}