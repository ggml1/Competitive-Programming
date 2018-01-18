#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	string a;

	while(cin >> a && a.compare("END") != 0){
		string prev = to_string(a.size());
		int cnt = 1;

		if(prev == a) cout << cnt << endl;
		else{
			while(1){
				++cnt;
				string x = to_string(prev.size());

				if(x == prev){
					cout << cnt << endl;
					break;
				} else prev = x;
			}
		}
	}

	return 0;
}