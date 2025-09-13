#include <bits/stdc++.h>
using namespace std;

int t;
string s;
int cnt, twos, threes;

void init() {
    cnt = 0, twos = 0;
    threes = 0;
    cin >> s;
}

int main() {
    cin >> t; while(t--) {
        init();
        int len = s.length();
        for(int i = 0; i < len; i++) {
            int x = s[i] - '0';
            if(x == 2) twos ++;
            if(x == 3) threes ++;
            cnt = (cnt + x) % 9;
        }
        bool flag = false;
        if(cnt == 0){flag = true;}
        cnt = 9 - cnt;
        while(twos != 0){
            if(cnt == 0){flag = true; break;}
            if((cnt + 9) % 6 == 0 && (cnt + 9) / 6 <= threes) {flag = true; break;}
            if(cnt % 6 == 0 && cnt / 6 <= threes) {flag = true; break;}
            cnt -= 2; twos--;
            if(cnt < 0) cnt += 9;
            
        }
        if(cnt == 0) {flag = true;}
        while(threes != 0) {
            if(cnt == 0) {flag = true; break;}
            cnt -= 6; threes--;
            if(cnt < 0) cnt += 9;
        }
        if(cnt == 0) {flag = true;}
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}