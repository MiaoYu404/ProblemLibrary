#include <iostream>
using namespace std;

int T, k, m;

int main(){
    cin >> T;
    while(T--){
        cin >> k >> m;
        int maxn, K;
        cin >> K;
        int num = 1;
        for(int i = 1; i <= k; i++) num *= 2;
        for(int i = 1; i <= num; i++){
            int x;
            cin >> x;
            if(x + m > maxn) maxn = x;
        }
        if(K >= maxn) cout << "Kotori" << endl;
        else cout << "Yoshino" << endl;
    }
}