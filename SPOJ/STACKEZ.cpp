#include <cstdio>
 
using namespace std;
 
int arr[1000005];
 
int main(){ 
 
    int t;
 
    scanf("%d", &t);
 
    int a, front = 0, k = 0, b;
 
    while(t--){
        scanf("%d", &a);
        switch(a){
            case 1:
                scanf("%d", &b);
                arr[k] = b;
                k++;
                front++;
                break;
            case 2:
                if(k != 0){
                    front--;
                    k--;
                }
                break;
            case 3:
                if(k != 0){
                    printf("%d\n", arr[front-1]);
                } else printf("Empty!\n");
                break;
        }
    }
 
 
    return 0;
} 