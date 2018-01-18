#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 5;

int h, d, day, done;
double u, f, pos;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	while(cin >> h && h != 0){
		cin >> u >> d >> f;

		pos = 0.0;

		done = day = 0;

		double rate = u*f/100.0;

		while(1){
			day++;
			pos += u;

			if(pos > h){
				cout << "success on day " << day << endl;
				done = 1;
				break;
			}

			pos -= d;

			u -= rate;

			if(u < d) break;
		}

		if(!done){
			while(pos >= 0){
				day++;
				pos += max(u, 0.0000000) - d;
				u -= rate;
			}

			cout << "failure on day " << day << endl;
		}
	}

	return 0;
}