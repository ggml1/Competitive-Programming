#include <bits/stdc++.h>

#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int ms = 1e7 + 1;

bool sieve[ms];
vector<int> primes;

void doSieve(int n){
	memset(sieve, true, sizeof(sieve));

	for(int i = 2; i <= n; ++i){
		if(sieve[i]){
			for(int j = 2*i; j < ms; j += i){
				sieve[j] = false;
			}
		}
		primes.push_back(i);
	}
}
 
int main(){
    //ios::sync_with_stdio(0); cin.tie(0);

    doSieve(ms);

    int n;

    while(scanf("%d", &n) != EOF){

    	printf("1");

    	if(sieve[n] && n != 1){
    		printf(" x %d\n", n);
    	} else{
    		for(int i = 0; n > 1; i++){
    			while(n%primes[i] == 0){
    				printf(" x %d", primes[i]);
    				n /= primes[i];
    			}
    			if(sieve[n] && n != 1){
    				printf(" x %d", n);
    				break;
    			}
    		}

    		printf("\n");
    	}
    }


    return 0;
}
