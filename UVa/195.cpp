#include <bits/stdc++.h>

using namespace std;

bool comp(char a, char b){
	char x = tolower(a);
	char y = tolower(b);

	if(x == y) return (isupper(a) && islower(b));
	return x < y;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; cin.ignore();

	while(t--){
		string a; getline(cin, a);

		sort(a.begin(), a.end(), comp);

		do{
			cout << a << endl;
		}while(next_permutation(a.begin(), a.end(), comp));
	}

	return 0;
}