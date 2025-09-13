// P8232 [AGM 2022 资格赛] 2048 花园
// GYM 103604 D. Rainy Garden
// tag: 暴力
// 难度: 普及+ / 提高
// link:
//      Luogu: https://www.luogu.com.cn/problem/P8232
//      Codeforces: https://codeforces.com/gym/103604/problem/D

#include <bits/stdc++.h>
using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};
const int N = 3000;

vector<int> deal (vector<int> nums) {
    vector<int> rsl;
    while(!nums.empty()) {
        int n = nums.back();
        nums.pop_back();
        if (n <= 0) continue;
        while (!rsl.empty()) {
            int t = rsl.back();
            if (t == n) {
                rsl.pop_back(); n += 1;
            } else {
                break;
            }
        }
        rsl.push_back(n);
    }
    reverse(rsl.begin(), rsl.end());
    return rsl;
}

int n, m, k;
int tmpTable[N][N];

int solve(int step, int a[]) {
    int ans = 0;
    int x1 = -1, y1 = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, a[i * m + j]);
            if (a[i * m + j] == 0 and x1 == -1) {
                x1 = i, y1 = j;
            }
        }
    }
    if (x1 == -1 and y1 == -1) return max(1, ans);
    if (step == 0) return max(1, ans);

    for (int dir = 0; dir < 4; dir++) {
        int x = 1, y = 1;
        while (x >= 1 and x <= n and y >= 1 and y <= m) {
            vector<int> tmp;
            int xx = x, yy = y;
            while (xx >= 1 and xx <= n and yy >= 1 and yy <= m) {
                tmp.push_back((xx == x1 and yy == y1) ? 1 : a[xx * m + yy]);
                xx += abs(dirX[dir]); yy += abs(dirY[dir]);
            }

            if (dir == 0 or dir == 3) reverse(tmp.begin(), tmp.end());
            
            tmp = deal(tmp);
            vector<int> rsl; int len = ((dir % 2) ? m : n) - tmp.size();
            while(len--) rsl.push_back(0);
            for (auto val : tmp) rsl.push_back(val);

            if (dir == 0 or dir == 3) reverse(rsl.begin(), rsl.end());

            int index = 0; xx = x, yy = y;
            for (auto val : rsl) {
                tmpTable[xx][yy] = val;
                xx += abs(dirX[dir]); yy += abs(dirY[dir]);
            }

            if (dir % 2) x++; else y++;
        }

        int b[N];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                b[i * m + j] = tmpTable[i][j];
            }
        }

        ans = max(ans, solve(step - 1, b));
    }

    return ans;
}

int a[N];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        stringstream str(s);
        str >> n >> m >> k;
        
        vector<int> para;
        for (int i = 1; i <= n; i++) {
            getline(cin, s);
            stringstream tmp(s);
            for (int j = 1; j <= m; j++) {
                int x; tmp >> x;
                a[i * m + j] = x;
            }
        }
        
        cout << solve(k, a) << endl;
    }
    return 0;
}