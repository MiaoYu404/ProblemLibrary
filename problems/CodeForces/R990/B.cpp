#include <bits/stdc++.h>
using namespace std;

int ch[26];
int t, n;
string s; 

void init() {
    cin >> n;
    memset(ch, 0, sizeof(ch));
    cin >> s;
    for(int i = 0; i < n; i++) {
        ch[s[i] - 'a'] ++;
    }
}

int main() {
    cin >> t;
    while(t--) {
        init();
        int maxn = 0, minn = 15;
        char a, b;
        for(int i = 0; i < 26; i++) {
            if(ch[i] == 0) continue;
            char ele = (char)((int)'a' + i);
            if(maxn < ch[i]) {maxn = ch[i]; a = ele;}
            if(minn > ch[i]) {minn = ch[i]; b = ele;}
            if(maxn == minn && ele != a) b = ele;
        }

        bool flag = false;
        for(auto x : s) {
            if(x == b && !flag) {
                cout << a; flag = true; continue;
            }
            cout << x;
        }
        cout << endl;
    }
}