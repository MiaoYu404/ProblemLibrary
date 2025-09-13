#include <iostream>
using namespace std;

int a[20];
int main(){
    int n = 0;
    double cnt = 0;
    for(int k = 1; k <= 15; k++){
        while(cnt <= k){
            double val = 1.0 / ++n;
            cnt += val;
            if(cnt > k){
                a[k] = n; break;
            }
        }
    }
    int k;
    cin >> k;
    cout << a[k];
}