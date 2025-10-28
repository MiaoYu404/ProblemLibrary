#include <bits/stdc++.h>

using namespace std;
tuple<int, string, string> s[26];
string s1, s2;

int main() {
    cin >> s1 >> s2;
    for (int i = 0; i < 26; i++) {
        bool f1 = true, f2 = true;
        string pre, suf;
        for (int j = 1; j < s1.length(); j++) {
            if ((int) s1[j] - 'a' == i) {
                f1 = false;
                pre = s1.substr(0, j);
                break;
            }
        }
        for (int j = s2.length() - 2; j >= 0; j--) {
            if ((int) s2[j] - 'a' == i) {
                f2 = false;
                suf = s2.substr(j);
                break;
            }
        }
        int len = 0;
        if (f1 || f2) len = INT_MAX;
        else len = pre.length() + suf.length();
        s[i] = make_tuple(len, pre, suf);
    }
    sort(s, s + 26);
    if(get<0>(s[0]) == INT_MAX) cout << -1 << '\n';
    else cout << get<1>(s[0]) + get<2>(s[0]) << '\n';
}