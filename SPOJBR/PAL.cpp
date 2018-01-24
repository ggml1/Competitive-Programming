#include <bits/stdc++.h>

using namespace std;

const int N = 3500;
const int inf = INT_MAX;

int n, teste, parts[N];
bool pal[N][N];
string s;

int main(){
	ios::sync_with_stdio(0);

	teste = 0;

	while(cin >> n && n){
		++teste;

		cin >> s;

		memset(pal, 0, sizeof(pal));

		for(int i = 0; i < n; ++i){
			pal[i][i] = 1;
			if(i != n - 1) pal[i][i + 1] = s[i] == s[i + 1];
		}

		for(int i = 2; i <= n; ++i){
			for(int j = 0; j <= n - i; ++j){
				int k = j + i - 1;

				if(i == 2) pal[j][k] = (s[j] == s[k]);
				else pal[j][k] = (s[j] == s[k] && pal[j + 1][k - 1]);
			}
		}

		for(int i = 0; i < n; ++i){
			if(pal[0][i]) parts[i] = 1;
			else{
				parts[i] = inf;

				for(int j = 0; j < i; ++j){
					if(pal[j + 1][i] && parts[i] > parts[j] + 1){
						parts[i] = parts[j] + 1;
					}
				}
			}
		}

		cout << "Teste " << teste << endl << parts[n - 1] << endl << endl;
	}

	return 0;
}