#include <bits/stdc++.h>
 
#define fi first
#define se second
#define LIMIT 1000000007
#define dbg(x) cout << "variable '" << #x << << "' -> " << x << '\n';
#define oi() cout << "oi" << endl;
#define fr(a, b, c) for(int a = b, _ = c; a < _; ++a)
 
typedef unsigned long long ull;
 
using namespace std;
 
struct folha{
	ull data;
	int alt;
	int rn;
	int ln;
	struct folha* esq;
	struct folha* dir;
};
 
int nodeAmountL(struct folha* raiz){
	if(raiz == NULL) return 0;
	return raiz->ln;
}
 
int nodeAmountR(struct folha* raiz){
	if(raiz == NULL) return 0;
	return raiz->rn;
}
 
struct folha* newNode(ull data){
	struct folha* temp = (struct folha*) malloc(sizeof(struct folha));
 
	temp->data = data;
	temp->dir = NULL;
	temp->esq = NULL;
	temp->alt = 1;
	temp->rn = 0;
	temp->ln = 0;
 
	return temp;
}
 
int getHeight(struct folha* raiz){
	if(raiz == NULL) return 0;
	return raiz->alt;
}
 
struct folha* rotateEsq(struct folha* raiz){
	struct folha *x = raiz->dir;
	// raiz->dir = (raiz->esq)->dir;
	raiz->dir = x->esq;
	raiz->rn = x->ln;
	x->esq = raiz;
 
	raiz->alt = max(getHeight(raiz->esq), getHeight(raiz->dir)) + 1;
 
	x->alt = max(getHeight(x->esq), getHeight(x->dir)) + 1;
 
	x->ln = 1 + nodeAmountR(x->esq) + nodeAmountL(x->esq);
 
	return x;
}
 
struct folha* rotateDir(struct folha* raiz){
	struct folha* x = raiz->esq;
	// raiz->esq = (raiz->dir)->esq;
	raiz->esq = x->dir;
	raiz->ln = x->rn;
	x->dir = raiz;
 
	raiz->alt = max(getHeight(raiz->esq), getHeight(raiz->dir)) + 1;
	x->alt = max(getHeight(x->esq), getHeight(x->dir)) + 1;
 
	x->rn = 1 + nodeAmountR(x->dir) + nodeAmountL(x->dir);
 
	return x;
}
 
int getBalance(struct folha* raiz){
	if(raiz == NULL) return 0;
	return getHeight(raiz->esq) - getHeight(raiz->dir);
}
 
struct folha* insert(struct folha* raiz, ull data){
	if(raiz == NULL){
		return newNode(data);
	}
 
	if(raiz->data < data){
		raiz->rn += 1;
		raiz->dir = insert(raiz->dir, data);
	}
	else if(raiz->data > data){
		raiz->ln += 1;
		raiz->esq = insert(raiz->esq, data);
	}
	else return raiz;
 
	raiz->alt = 1 + max(getHeight(raiz->esq), getHeight(raiz->dir));
 
	int balance = getBalance(raiz);
 
	if(balance > 1 && data < (raiz->esq)->data) return rotateDir(raiz);
 
	if(balance < -1 && data > (raiz->dir)->data) return rotateEsq(raiz);
 
	if(balance > 1 && data > (raiz->esq)->data){
		raiz->esq = rotateEsq(raiz->esq);
		return rotateDir(raiz);
	}
 
	if(balance < -1 && data < (raiz->dir)->data){
		raiz->dir = rotateDir(raiz->dir);
		return rotateEsq(raiz);
	}
 
	return raiz;
}
 
void procura(struct folha* raiz, ull proc, int pos){
	if(raiz == NULL){
		cout << "Data tidak ada" << endl;
		return;
	}
 
	if(proc < raiz->data){
		procura(raiz->esq, proc, pos);
	} else if(proc > raiz->data){
		procura(raiz->dir, proc, pos+1+raiz->ln);
	} else{
		cout << pos + raiz->ln << endl;
	}
}
 
int main()
{
	ios::sync_with_stdio(0); cout.tie(); cin.tie();
 
	int n; cin >> n;
 
	struct folha* raiz = NULL;
 
	int dist;
 
	while(n--){
		ull x, y; cin >> x >> y;
		switch(x){
			case 1:
				raiz = insert(raiz, y);
				break;
			case 2:
				procura(raiz, y, 1);
				break;
		}
	}
 
    return 0;
} 