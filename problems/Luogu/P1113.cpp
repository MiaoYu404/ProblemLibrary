#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 10;
int cur[maxn];
int ans = 0;

int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> i;
        int len = 0; cin >> len;

        int x; cin >> x; int largest = 0;

        while (x != 0) {
            largest = max(cur[x], largest);
            cin >> x;
        }
        cur[i] = largest + len;
        ans = max(ans, cur[i]);
    }

    cout << ans;

    return 0;
}