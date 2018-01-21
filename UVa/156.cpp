#include <bits/stdc++.h>

using namespace std;

vector<pair<string, string>> words;
vector<string> anana;
string x;
map<string, int> all;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	while(getline(cin, x) && x.compare("#") != 0){
		stringstream k(x);

		string a;

		while(k >> a){
			string b = a;

			for(char &c : a){
				c = tolower(c);
			}

			sort(a.begin(), a.end());

			all[a]++;
			words.push_back({b, a});
		}
	}

	for(auto s : words){
		string s1 = s.first;
		string s2 = s.second;

		if(all[s2] == 1){
			anana.push_back(s1);
		}
	}

	sort(anana.begin(), anana.end());

	for(string s : anana){
		cout << s << endl;
	}

	return 0;
}