#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;

const int N = 4e4 + 10;
int phi[N];

void euler(int n) {
    for (int i = 2; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    if (n == 1) {cout << 0; return 0;}
    euler(n);
    i64 ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans += phi[i] * 2;
    }
    cout << ans + 3;
    return 0;
}