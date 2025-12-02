#include <bits/stdc++.h>
using namespace std;

string s;
int vow, con, N, G, Y;

int main() {
    cin >> s;
    int len = s.length();
    //cout << s.length() << endl;
    for(int i = 0; i < len; i++) {
        int ch = s[i];
        if(ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U') vow++;
        else if (ch == 'N') N++;
        else if (ch == 'G') G++;
        else if (ch == 'Y') Y++;
        else con++;
    }

    int NG = min(N, G); N -= NG; G -= NG;
    //step 1
    /*
    if( (vow + con + N + G + NG + Y) % 3 == 0 && con + N + G + NG + Y - 2 * vow > 0) {
        cout << len << endl; return 0;
    }
    */
    int tmp = min(vow , (NG + con + N + G) / 2);
    vow -= tmp;
    tmp *= 2;

    if (vow != 0) {
        tmp = min(vow, Y / 2);
        vow -= tmp;
        tmp *= 2;
        
        if(vow != 0){
            cout << len - vow << endl;
            return 0;
        }
        // vow == 0
        Y -= tmp; if(Y % 3 == 0){
            cout << len << endl;
            return 0;
        }
        else if (Y % 3 == 1) {
            if(NG >= 2) cout << len << endl;
            else cout << len - 1 << endl;
            return 0;
        }else {
            // 2
            if (NG >= 1) cout << len << endl;
            else cout << len - 2 << endl;
            return 0;
        }
    }else{
        //vow  == 0
        int tmpN = min(N, tmp); tmp -= tmpN;
        int tmpG = min(G, tmp); tmp -= tmpG;
        N -= tmpN; G -= tmpG;

        int tmpNG = NG; // 暂存一下NG的数量
        NG -= tmp;
        int tmp = min((NG) / 2, Y);
        Y -= tmp; if(Y != 0){
            if(tmpNG >= Y * 2) cout << len << endl;
            else cout << len - (Y - tmpNG / 2) << endl;
            return 0;
        }else {
            NG -= tmp; cout << len - NG << endl;
            return 0;
        }
    }
}

