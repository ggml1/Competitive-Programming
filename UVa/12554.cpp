#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);

	int n; cin >> n;

	string names[n];

	for(int i = 0; i < n; ++i){
		cin >> names[i];
	}

	string song[17] = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };

	int now = 0;

	for(int i = 0; i < n; ++i){
		cout << names[i] << ": " << song[now] << endl;

		now = (now + 1)%16;
	}

	int act = 0;

	while(now != 16){
		cout << names[act] << ": " << song[now] << endl;
		now++;
		act = (act + 1)%n;
	}

	return 0;
}