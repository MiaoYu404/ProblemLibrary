// P1204 (from USACO)
// tag: 模拟、排序、差分
// 难度: 普及-
// link: https://www.luogu.com.cn/problem/P1204

#include <bits/stdc++.h>
using namespace std;

// 我勒个暴力
/*
bool cmp(const pair<int, int> a, const pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > pairs;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        pairs.push_back(make_pair(a, b));
    }

    sort(pairs.begin(), pairs.end(), cmp);

    int bg = 0, ed = 0;
    int ans1 = 0, ans2 = 0;
    while (!pairs.empty()) {
        pair<int, int> x = pairs[0];
        pairs.assign(pairs.begin() + 1, pairs.end());
        bg = x.first, ed = x.second;
        
        while (!pairs.empty()) {
            pair<int, int> p = pairs[0];
            if (p.first <= ed) {
                pairs.assign(pairs.begin() + 1, pairs.end());
                ed = max(ed, p.second);
            } else break;
        }

        ans1 = max(ed - bg, ans1);
        if (!pairs.empty()) {
            pair<int, int> p = pairs[0];
            ans2 = max(p.first - ed, ans2);
        } // empty then break
    }

    cout << ans1 << " " << ans2 << endl;
}

int main () {
    solve();
    return 0;
}
*/

const int N = 1e6 + 10;
int dif[N];

int main () {
    int n; cin >> n;
    int st = N, ed = 0;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        dif[l]++; dif[r]--;
        st = min(l, st);
        ed = max(r, ed);
    }

    int ans1 = 0, ans2 = 0;
    bool counting = false;
    int cur = 0, cnt = 0;
    for (int i = st; i <= ed; i++) {
        cur += dif[i];
        if ((cur == 0 and counting != 0) or (cur != 0 and counting == 0)) // different
        {
            if (cur == 0) {
                counting = false;
                ans1 = max(ans1, cnt);
                cnt = 0;
            } else {
                counting = true;
                ans2 = max(ans2, cnt);
                cnt = 0;
            }
        }
        cnt++;
    }
    cout << ans1 << " " << ans2;
}