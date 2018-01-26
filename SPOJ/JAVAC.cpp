#include <bits/stdc++.h>

using namespace std;

int check(string s, int n){
	if(isupper(s[0]) || s[n - 1] == '_' || s[0] == '_') return 0;

	bool java, cpp = java = false;

	for(int i = 0; i < n; ++i){
		if(isupper(s[i])){
			if(cpp) return 0;

			java = true;
		} else if(s[i] == '_'){
			if(java || s[i + 1] == '_') return 0;

			cpp = true;
		}
	}

	if(cpp) return 1;

	return 2;
}

string transfC(string s, int n){
	string ret = "";

	for(int i = 0; i < n; ++i){
		if(isalpha(s[i])){
			if(isupper(s[i])){
				ret += '_';
				ret += tolower(s[i]);
			} else ret += s[i];
		}
	}

	return ret;
}

string transfJ(string s, int n){
	string ret = "";

	for(int i = 0; i < n; ++i){
		if(isalpha(s[i])){
			ret += s[i];
		} else{
			if(i == n - 1) break;
			else if(i == 0) continue;
			else{
				while(s[i] == '_'){
					++i;
				}
				ret += toupper(s[i]);
			}
		}
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(0);

	string s;

	while(getline(cin, s)){
		int n = s.length();

		int lang = check(s, n);

		if(!lang) cout << "Error!\n";
		else if(lang == 1) cout << transfJ(s, n) << endl;
		else cout << transfC(s, n) << endl;
	}

	return 0;
}