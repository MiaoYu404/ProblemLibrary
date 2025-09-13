#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
string s;

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> s;
        //aa
        bool flag = false;
        for (int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                flag = true; cout << s[i - 1] << s[i] << endl;
                break;
            }
        }
        //aba
        if(!flag) for (int i = 2; i < s.length(); i++) {
            if (s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i] != s[i - 2]) {
                flag = true; cout << s[i - 2] << s[i - 1] << s[i] << endl;
                break;
            }
        }
        //似啦
        if(!flag) cout << -1 << endl;
    }
}