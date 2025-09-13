#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int tt; cin >> tt; while (tt--) {
        string s; cin >> s;
        int len = s.length();

        int a = 0; while (s[a] == '1' and a < len) a++;
        if (a == len) {
            cout << 1 << " " << len << ' ' << 1 << ' ' << 1 << '\n';
            continue;
        }

        int l, r;
        int rsl = a;
        for (int i = 0; i < a; i++) {
            if (!((int)s[i] xor (int)s[a])) continue;
            // 找到第一个合适的起点
            // 有 len - a 的空间
            for (int j = 0; j <= len - a; j++) {
                if ((int)s[i + j] xor (int)s[a + j]) {
                    if (rsl <= a + j) {
                        l = i, r = i + (len - a), rsl = a + j;
                    }
                } else {break;}
            }
        }

        cout << 1 << " " << len << " ";
        cout << l + 1 << " " << r << endl;
    }
    return 0;
}