#include <bits/stdc++.h>
#include <locale>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

const int ms = 101;

int dur, rec;
double loan, downP, rates[ms];

int main(){
	fast_io; cout << fixed << setprecision(5);

	cin >> dur >> downP >> loan >> rec;

	while(dur > 0){
		for(int i = 0; i < rec; ++i){
			int x; double y; cin >> x >> y;

			for(int j = x; j < 101; ++j){
				rates[j] = y;
			}
		}

		double total = (loan + downP)*(1.0 - rates[0]);
		double owe = loan;
		double perMonth = (double) loan/dur;
		int ans = 0;

		while(owe > total){
			++ans;
			owe -= perMonth;
			total = (1.0 - rates[ans])*total;
		}

		cout << ans << ' ';

		if(ans != 1) cout << "months\n";
		else cout << "month\n";

		cin >> dur >> downP >> loan >> rec;
	}



    return 0;
}