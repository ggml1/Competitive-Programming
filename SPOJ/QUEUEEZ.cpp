#include <iostream>
 
using namespace std;
 
int arr[(int) 1000005];
 
int main(){ 
    ios::sync_with_stdio(0);
 
    int t;
 
    cin >> t;
 
    int a, front = 0, qtd = 0, k = 0, b;
 
    while(t--){
        cin >> a;
        switch(a){
            case 1:
                cin >> b;
                arr[qtd] = b;
                k++;
                qtd++;
                break;
            case 2:
                if(k != 0){
                    front++;
                    k--;
                }
                break;
            case 3:
                if(k != 0){
                    cout << arr[front] << endl;
                } else cout << "Empty!\n";
                break;
        }
    }
 
 
    return 0;
} 