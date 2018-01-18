#include <bits/stdc++.h>

using namespace std;

string x;

char subst(char c){
	if(c == 'A' || c == 'H' || c == 'I' || c == 'M' || c == 'O' || (c >= 'T' && c <= 'Y') || c == '1' || c == '8') return c;
	if(c == 'E') return '3';
	if(c == '3') return 'E';
	if(c == 'J') return 'L';
	if(c == 'L') return 'J';
	if(c == 'S') return '2';
	if(c == '2') return 'S';
	if(c == 'Z') return '5';
	if(c == '5') return 'Z';

	return '#';
}

bool mirror(string x){
	string k = x;

	reverse(k.begin(), k.end());

	for(char &c : k){
		c = subst(c);
	}

	return k == x;
}

bool pal(string k){
	for(int i = 0; i < k.size()/2; ++i){
		if(k[i] != k[k.size() - 1 - i]) return 0;
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	while(getline(cin, x)){
		bool m = mirror(x);
		bool p = pal(x);

		if(m && p) cout << x << " -- is a mirrored palindrome.\n";
		else if(m) cout << x << " -- is a mirrored string.\n";
		else if(p) cout << x << " -- is a regular palindrome.\n";
		else cout << x << " -- is not a palindrome.\n";

		cout << endl;
	}

	return 0;
}