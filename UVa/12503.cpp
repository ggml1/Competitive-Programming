#include <bits/stdc++.h>
#include <locale>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

string get(string instructions[], string k){
	string b, c; int x;

	stringstream a(k);

	a >> b >> c >> x;

	return instructions[x];
}

int main(){
	fast_io; cout << fixed << setprecision(5);

	int t; cin >> t;

	while(t--){
		int a; cin >> a; cin.ignore();

		string instructions[a + 1];

		int x = 0;

		for(int i = 1; i <= a; ++i){
			string k; getline(cin, k);

			if(k.size() > 5){
				instructions[i] = get(instructions, k);
			} else{
				instructions[i] = k;
			}

			x += (instructions[i].compare("RIGHT") == 0);
			x -= (instructions[i].compare("LEFT") == 0);
		}

		cout << x << endl;
	}

    return 0;
}