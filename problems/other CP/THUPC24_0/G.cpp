#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int tt;
int W, M, WW, MM;

void init() {
    string s; cin >> s;
        int len = s.length();
        W = 0, M = 0, WW = 0, MM = 0;
        int W_ = 0, M_ = 0, head = 0;
        // none head = 0, W head = 1, M head = 2;

        if (s[0] == 'W') head = 1;
        if (s[0] == 'M') head = 2;

        for (int i = 0; i < len; i++) {
            if (s[i] == 'X') {
                if (W_ and M_) {
                    // 找形如 MxxxM 和 WxxxW （中间有一个不一样）
                    if (head == 1 and s[i - 1] == 'W') WW++;
                    else if (head == 2 and s[i - 1] == 'M') MM++;
                }
                else if (W_ and !M_) W++;
                else if (!W_ and M_) M++;
                W_ = 0; M_ = 0; head = 0;
                continue;
            }

            if (s[i - 1] == 'X') {
                if (s[i] == 'W') head = 1;
                if (s[i] == 'M') head = 2;
            }

            if (s[i] == 'W') W_ = 1;
            if (s[i] == 'M') M_ = 1;
        }

        if (W_ and M_) {
            // 找形如 MxxxM 和 WxxxW （中间有一个不一样）
            if (head == 1 and s[len - 1] == 'W') WW++;
            else if (head == 2 and s[len - 1] == 'M') MM++;
        }
        else if (W_ and !M_) W++;
        else if (!W_ and M_) M++;
        W_ = 0; M_ = 0; head = 0;

        //cout << W << " " << M << " " << WW << " " << MM << " " << endl;
}
int main() {
    cin >> tt;
    while (tt--) {
        init();
        if (W + WW == M + MM) {
            if (MM == 0) cout << "Water" << endl;
            else cout << "Draw" << endl;
        }
        else if (W + WW == M + MM + 1) {
            if (WW == 0) cout << "Menji" << endl;
            else cout << "Draw" << endl;
        }
        else if (W + WW < M + MM) {
            cout << "Water" << endl;
        }else {
            cout << "Menji" << endl;
        }
    }
    return 0;
}

/*
WXMWXMWMXMWXMWX
*/