#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector< pair<int, int> > ans;
void change(vector< vector<int> > &num, int x, int y) {
    for (int i = 1; i <= 4; i++) {
        num[x][i] += 1;
        num[x][i] %= 2;
    }
    for (int i = 1; i <= 4; i++) {
        num[i][y] += 1;
        num[i][y] %= 2;
    }
    num[x][y] = (num[x][y] + 1) % 2;
}
/*
bool solve(vector< vector<int> > &mp) {
    vector< pair<int, int> > tmpAns;
    for (int i = 2; i <= 3; i++) {
        int cnt = 0;
        for (int j = 1; j <= 4; j++) {
            if (mp[i][j] != mp[i - 1][j]) cnt++;
        }
        if (cnt == 0) continue;
        else if (cnt == 3) {
            for (int j = 1; j <= 4; j++) {
                if (mp[i][j] == mp[i - 1][j]) {
                    tmpAns.push_back(make_pair(i, j));
                    change(mp, i, j);
                    break;
                }
            }
        }
        else {
            return false;
        }
    }

    if (mp[4][1] != mp[4][2] or mp[4][1] != mp[4][3] or mp[4][1] != mp[4][4]) return false;
    int cnt = 0;
    for (int j = 1; j <= 4; j++) {
        if (mp[4][j] != mp[3][j]) cnt++;
    }
    if ((cnt + mp[4][1]) % 2 != 1) return false;
    for (int j = 1; j <= 4; j++) {
        if (mp[3][j] == 0) {
            change(mp, 4, j);
            tmpAns.push_back(make_pair(4, j));
        }
    }
    while (!tmpAns.empty()) {
        ans.push_back(tmpAns.back());
        tmpAns.pop_back();
    }
    return true;
}
*/

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    vector< vector<int> > a(5);
    for (int i = 1; i <= 4; i++) {
        string s; cin >> s;
        a[i].push_back(0);
        for (int j = 0; j < 4; j++) {
            if (s[j] == '-') a[i].push_back(1);
            else a[i].push_back(0);
        }
    }

    vector< pair<int, int> > opt; int minLen = 0x3F;
    /*
    for (int i = 0; i < 16; i++) {
        int act = i;
        vector< vector<int> > tmp(a);
        for (int j = 1; j <= 4; j++, act /= 2) {
            if (act % 2) {
                change(tmp, 1, j);
                ans.push_back(make_pair(1, j));
            }
        }

        if (solve(tmp)) {
            if (minLen > ans.size()) {
                minLen = ans.size();
                opt = ans;
            }
        }
        while (!ans.empty()) { ans.pop_back(); }
    }
    */
    for (int i = 0; i < (1<<16); i++) {
        int act = i;
        vector< vector<int> > tmp(a);
        for (int k = 0; k <= 15; k++, act /= 2) {
            if (act % 2) {
                change(tmp, k / 4 + 1, k % 4 + 1);
                ans.push_back(make_pair(k / 4 + 1, k % 4 + 1));
            }
        }
        bool flag = true;
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                if (!tmp[i][j]) flag = false;
            }
        }
        if (flag) {
            if (minLen > ans.size()) {
                minLen = ans.size();
                opt = ans;
            }
        }
        while (!ans.empty()) { ans.pop_back(); }
    }
    

    cout << opt.size() << '\n';
    sort(opt.begin(), opt.end());
    for (int i = 0; i < minLen; ++i) {
        cout << opt[i].first << " " << opt[i].second << '\n';
    }
    return 0;
}