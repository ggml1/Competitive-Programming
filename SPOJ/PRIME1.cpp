#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int mx = 1e6 + 5;
 
bool sieve[mx];
vector<ll> primes;
 
void erat(){
	memset(sieve, 1, sizeof(sieve));
 
	sieve[1] = sieve[0] = 0;
 
	for(int i = 2; i < mx; ++i){
		if(sieve[i]){
			for(int j = i + i; j < mx; j += i){
				sieve[j] = 0;
			}
			primes.push_back((ll) i);
		}
	}
}
 
bool isPrime(ll x){
	for(ll k : primes){
		if(k * k > x) break;
 
		if(x%k == 0) return 0;
	}
 
	return 1;
}
 
int main(){
 
	int t; scanf("%d", &t);
 
	erat();
 
	int kse = 0;
 
	while(t--){
		++kse;
 
		if(kse != 1) printf("\n");
 
		int l, u; scanf("%d%d", &l, &u);
 
		for(int i = l; i <= u; ++i){
			if(i < mx){
				if(sieve[i]) printf("%d\n", i);
			} else{
				if(isPrime((ll) i)) printf("%d\n", i);
			}
		}
	}
 
	return 0;
}  