#include <bits/stdc++.h>

#define fast_io ios::sync_with_stdio(0);cin.tie(0)

using namespace std;

int main(){
	fast_io;

	string a;

	int mark = 1;

	while(getline(cin, a)){
		string x;

		int n = a.size();

		for(int i = 0; i < n; ++i){
			if(a[i] == '"'){
				if(mark){
					x += "``";
				} else{
					x += "'";
					x += "'";
				}

				mark = 1 - mark;
			} else x += a[i];
		}

		cout << x << endl;
	}

    return 0;
}