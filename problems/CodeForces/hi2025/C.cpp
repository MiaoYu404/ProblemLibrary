#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 返回第 k 位的值
int check_kth_bit (int x, int k) {
    return (x >> k) & 1;
}

// 打印二进制
void print_on_bits (int x) {
    for (int k = 0; k < 32; k++) {
        if (check_kth_bit (x, k))
            cout << k << " ";
    }
    cout << '\n';
}

int main () {
    int tt; cin >> tt; while (tt--) {
        ll l, r; cin >> l >> r;
        int len = 31; while (!check_kth_bit(r, len)) --len;
        string lb, rb;
        for (int k = len; k >= 0; --k) 
            if (check_kth_bit (l, k)) lb += '1';
            else lb += '0';
        for (int k = len; k >= 0; --k) 
            if (check_kth_bit (r, k)) rb += '1';
            else rb += '0';
        
        int a; // 第一个 lb = 1, rb = 0 的位置
        for (a = 0; a <= len; a++) {
            if (lb[a] != rb[a]) break;
        }
        // 答案可以确定了 2^(len + 1) - 1 - (1 << (len - a - 1))
        // 2^(len + 1) - 1 - (2^(len - a - 1) - 1)
        // 和 r
        ll ans1 = r - (1 << (len - a));
        for (int i = len - a - 1; i >= 0; --i) {
            if (!check_kth_bit(ans1, i)) ans1 += (1 << i);
        }
        //ll ans1 = (1 << (len + 1)) - 1 - (1 << (len - a));
        //ll ans2 = (1 << (len + 1)) - (1 << (len - a));
        ll ans2 = ans1 + 1;

        cout << ans1 << " ";
        cout << ans2 << " ";
        for (int i = l; i <= r; ++i){
            if (i != ans1 and i != ans2) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}