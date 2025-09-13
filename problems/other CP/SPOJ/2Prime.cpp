#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    int m, n;
    while(t--){
        cin >> m >> n;
        for(int i = m; i <= n; i++){
            if(i == 1) continue;
            bool flag = true;
            for(int j = 2; j <= sqrt(i); j++)
                if(i % j == 0){flag = false; break;}
            if(flag) cout << i << endl;
        }
        cout << endl;
    }
}