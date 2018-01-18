#include <bits/stdc++.h>

using namespace std;

int r, p, opt, besto, caso;
double price, bestp;
string x, ans, name;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	caso = 0;

	while(cin >> r >> p && (r || p)){
		caso++;

		if(caso != 1) cout << endl;

		cin.ignore();

		for(int i = 0; i < r; ++i){
			getline(cin, x);
		}

		bestp = 1e18;
		opt = besto = 0;

		for(int i = 0; i < p; ++i){
			getline(cin, name);
			cin >> price >> opt; cin.ignore();

			for(int j = 0; j < opt; ++j){
				getline(cin, x);
			}

			if(opt > besto || (opt == besto && price < bestp)){
				ans = name;
				besto = opt;
				bestp = price;
			}
		}

		cout << "RFP #" << caso << endl << ans << endl;
	}

	return 0;
}