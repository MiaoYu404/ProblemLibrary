#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 返回第 k 位的值
int check_kth_bit (int x, int k) {
    return (x >> k) & 1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt; cin >> tt; while (tt--) {
        int n, k; cin >> n >> k;

        queue<ll> ans;
        for (int i = 31; i >= 0; i--) {
            if(check_kth_bit(k, i)) {
                ans.push((1 << i) - 1);
                ans.push(k - (1 << i) + 1);
                break;
            }
        }
        
        while (ans.size() < n) {
            ans.push(0);
        } 
        while (ans.size() > n) {
            ll a1 = ans.front(); ans.pop();
            ll a2 = ans.front(); ans.pop();
            ans.push(a1 + a2);
        }
        while (!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }
        cout << endl;
    }
}