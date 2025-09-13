#include <iostream>
#include <cmath>
#define ll long long
#define MOD 998244353
using namespace std;

const int maxn = 1e7 + 10;
ll tmp = 0;
ll edge[maxn], num[maxn];

void init(){
    edge[1] = 0, num[1] = 0;
    for(int i = 2; i <= 1e7+1; i++){
        tmp = ( (tmp + 1) * 2 - 1)% MOD;
        edge[i] = ( i * tmp ) % MOD;
        ll val = (num[i - 1] * i)% MOD;
        num[i] = ( edge[i] + val ) % MOD;
    }
}

int main(){
    init();
    int t; cin >> t;
    while(t--){
        int n = 0; cin >> n;
        cout << num[n] << endl;
    }
}