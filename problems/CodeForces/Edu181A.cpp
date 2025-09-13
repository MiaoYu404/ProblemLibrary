// Codeforces Edu R181 A. Difficult Contest
// tag: sort
// diff: *800
// link: https://codeforces.com/contest/2125/problem/A

#include <bits/stdc++.h>

const int N = 2e5 + 10;

int n;
char ch[N];
void solve() {
    std::cin >> ch;
    bool flag = true;
    int index = 0;
    while (ch[index + 2] != '\0') {
        if (ch[index] == 'F' and ch[index + 1] == 'F' and ch[index + 2] == 'T') flag = false;
        if (ch[index] == 'N' and ch[index + 1] == 'T' and ch[index + 2] == 'T') flag = false;
        index++;
    }
    if (!flag) std::sort(ch, ch + index + 2, std::greater<char>());
    std::cout << ch << std::endl;
}
int main () {
    int tt; std::cin >> tt; while (tt--) {
        solve();
    }
}