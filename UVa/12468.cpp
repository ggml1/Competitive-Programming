#include <bits/stdc++.h>
#include <locale>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

const int ms = 101;

int dur, rec;
double loan, downP, rates[ms];

int main(){
	fast_io; cout << fixed << setprecision(5);

	int a, b; cin >> a >> b;

	while(a != -1 || b != -1){
		int k = a - b + 100;
		int z = b - a + 100;

		k %= 100;
		z %= 100;

		cout << min(k, z) << endl;

		cin >> a >> b;
	}

    return 0;
}