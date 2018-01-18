#include <bits/stdc++.h>

using namespace std;

string x, y;

bool pal(string k){
	for(int i = 0; i < k.size()/2; ++i){
		if(k[i] != k[k.size() - 1 - i]) return 0;
	}

	return 1;
}

bool sqr(int x){
	double k = sqrt(x);
	int l = sqrt(x);

	return k == l;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int caso = 0;
	int t; cin >> t; cin.ignore();

	while(t--){
		getline(cin, x);
		
		++caso;

		y = "";

		for(char c : x){
			if(isalpha(c)){
				y += tolower(c);
			}
		}

		cout << "Case #" << caso << ":\n";

		if(pal(y) && sqr(y.length())){
			cout << sqrt(y.length()) << endl;
		} else cout << "No magic :(" << endl;
	}

	return 0;
}