#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	string blank;
	int t; cin >> t; cin.ignore(); getline(cin, blank);
	int caso = 0;

	while(t--){
		vector<pair<string, string>> words;

		string x;

		while(getline(cin, x) && x.compare("") != 0){
			string y = "";

			for(char c : x){
				if(!isspace(c)) y += c;
			}

			sort(y.begin(), y.end());

			words.push_back({x, y});
		}

		sort(words.begin(), words.end());

		int n = words.size();

		for(int i = 0; i < n; ++i){
			for(int j = i + 1; j < n; ++j){
				if(words[i].second == words[j].second){
					cout << words[i].first << " = " << words[j].first << endl;
				}
			}
		}

		if(t != 0) cout << endl;
	}

	return 0;
}