#include <bits/stdc++.h>

using namespace std;

string x, y;

bool pal(string k){
	for(int i = 0; i < k.size()/2; ++i){
		if(k[i] != k[k.size() - 1 - i]) return 0;
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	while(getline(cin, x) && x.compare("DONE") != 0){
		y = "";

		for(char c : x){
			if(isalpha(c)){
				y += tolower(c);
			}
		}

		if(pal(y)) cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
	}

	return 0;
}