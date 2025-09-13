#include <iostream>
using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        long long n, m; cin >> n >> m;
        if(m >= 19)   //大于19一定能过
        {
            cout << "Yes" << endl;
            continue;
        }
        int i;
        for(i = 2; i <= m; i++){
            if(n % i != i - 1){
                cout << "Yes" << endl;
                break;
            }
        }
        if(i == m + 1) cout << "No" << endl;
    }
}