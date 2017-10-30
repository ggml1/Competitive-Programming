#include <stdlib.h>
#include <stdio.h>
 
int fibSalvo[1100001];
int foo[100000];
 
int main(){
	short n, k = 0, qtd;
	long a, i, b;
	fibSalvo[1] = 0;
	fibSalvo[2] = 1;
	for(i = 3; i <= 1100000; ++i){
		fibSalvo[i] = (fibSalvo[i-1] + fibSalvo[i-2])%100000;
	}
 
	scanf("%li", &n);
 
	while(n--){
		++k;
 
		scanf("%li %li", &a, &b);
 
		printf("Case %d: ", k);
 
		for(i=a; i<=a+b; ++i){
			foo[fibSalvo[i]]++;
		}
 
		for(i = 0, qtd = 0; i < 100000; ++i){
			while(foo[i] != 0){
				printf("%li ", i);
				qtd++;
				if(qtd == 100) break;
				foo[i]--;
			}
			if(qtd == 100) break;
		}
		printf("\n");
		for(i=0; i<100000; ++i){
			foo[i] = 0;
		}
	}
	
 
	return 0;
} 