#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long a[20010];
long long ans;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= n - 1; i++){
        a[i + 1] = a[i] + a[i + 1];
        ans += a[i + 1];

        for(int j = i + 1; j <= n - 1; j++){
            if(a[j + 1] < a[j]){
                swap(a[j + 1], a[j]);
            }
            else break;
        }
    }
    cout << ans;
    return 0;
}