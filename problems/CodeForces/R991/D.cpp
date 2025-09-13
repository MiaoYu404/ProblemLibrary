#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
string s;
int num[maxn];

void init() {
    cin >> s;
    memset(num, 0, sizeof(num));
    for(int i = 0; i < s.length(); i++) {
        int x = s[i] - '0';
        num[i] = x;
    }
}

int main () {
    int t; cin >> t; while (t--) {
        init();
        int len = s.length();
        for (int i = 0; i < len - 1; i++) {
            int x = num[i]; //这个数
            int maxnn = x, index = 0;
            for(int j = 1; j <= min(8, len - i); j++) {
                int y = num[i + j];
                if(y - j > maxnn) {
                    maxnn = y - j; index = j;
                }
            }
            //找到了
            if(index == 0) {continue;}
            else{
                //update
                int tmp = num[i + index];
                for(int j = index; j > 0; j--) {
                    num[i + j] = num[i + j - 1];
                }
                num[i] = tmp - index;
            }
        }
        for(int i = 0; i < len; i++){
            int x = num[i];
            printf("%d", x);
        }
        printf("\n");
    }
}