#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];

int main(){
    int n, k;
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        int x = 0;
        cin >> x;
        a[i] = x;
        if(maxn < x) maxn = x;
    }

    int l = 1, r = maxn, cnt;
    while(l <= r){
        int mid = (l + r) >> 1;
        cnt = 0;
        for(auto x : a) cnt += x / mid;
        if(cnt < k) r = mid - 1;
        else l = mid + 1;
    }

    cout << r;

    return 0;
}