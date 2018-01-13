#include <bits/stdc++.h>
#include <locale>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

const int ms = 101;

int dur, rec;
double loan, downP, rates[ms];

int main(){
	fast_io; cout << fixed << setprecision(5);

	int t; cin >> t; int kse = 0;

	while(t--){
		++kse;
		int n; cin >> n;

		int total = 0, pM = 0, pJ = 0;

		for(int i = 0; i < n; ++i){
			int x; cin >> x;

			pM += (x/30)*10 + 10;
			pJ += (x/60)*15 + 15;
		}

		cout << "Case " << kse << ": ";

		if(pM < pJ){
			cout << "Mile " << pM << endl;
		} else if(pJ < pM){
			cout << "Juice " << pJ << endl;
		} else cout << "Mile Juice " << pJ << endl;
	}

    return 0;
}