#include <bits/stdc++.h>
#include <queue>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;
const int N = 3e5 + 10;
// a: origin, b: target
int n, m;
int mark = -1;
int a[N], b[N], cnt[N], pre[N], posi[N];

vector< vector<int> > needs(N);             // needs[i][j] means a[i] need insert b[j] before it;
set<int> dis[N];                            // x in dis[i] means a[x] is i till it can do addition;
bool markChange = false;
queue< pair<int, int> > ans1, ans2, ans3;   // before markChange, ans1; after ans3; otherwise ans2;

// d is distance, index is in a[]; 到这一步我们能知道 (index + d) % m == 1;
void f(int d, int index) {
    if (index == mark) {
        markChange = true;
        ans3.push(ans1.front());
        ans1.pop();
    }
    // 能来的都是可以直接开始插入的 所以只需要判断一下去哪里就可以了
    int cnt = 0;
    //int size = needs[index].size();
    for (int i = needs[index].size() - 1; i >= 0; i--) {
        int x = needs[index][i];
        // 拿一个下标出来
        // 行号是 (index + d) / m，x 是值
        if (!markChange) ans1.push(make_pair((index + d) / m, x));
        else ans3.push(make_pair((index + d) / m, x));

        cnt++;

        if (d + cnt >= m) continue;
        // if dis[d + cnt].end > index 那么 dis[].end 就是在 index 后面 那么就可以走
        if (!dis[d + cnt].empty()) while (*(dis[d + cnt].rbegin()) > index) {
            f(d + cnt, *(dis[d + cnt].rbegin()));
            // 最后一位删掉，因为它肯定全部加完了
            dis[d + cnt].erase( *(dis[d + cnt].rbegin()) );
        }

    }
    for (int add = 1; d + cnt + add < m; add++) {
        int from = d + cnt + add, to = d + add;
        if (!dis[from].empty()) while (*(dis[from].rbegin()) > index) {
            dis[to].insert( *(dis[from].rbegin()) );
            dis[from].erase( *(dis[from].rbegin()) );
        }
    }

}

void solve() {
    cin >> n >> m;
    mark = -1;
    //dis[0].clear();
    for (int i = 1; i <= n * m; i++) {
        dis[i].clear(); needs[i].clear();
        while (!ans1.empty()) ans1.pop();
        while (!ans2.empty()) ans2.pop();
        while (!ans3.empty()) ans3.pop();
    }
    
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
        cnt[i] = 0;
        pre[i] = 0;
        posi[i] = 0;
    }
    for (int i = 1; i <= n * m; i++) {
        cin >> b[i];
    }
    //a[i], b[i]; if (a[i] != b[j]) cnt[i] ++; 
    int i = 1, j = 1;
    for (; j <= n * m; j++) {
        if (a[i] == b[j]) {
            i++;
        } else {cnt[i]++; needs[i].push_back(j);}
    }

    pre[0] = 0;
    for (int i = 1; i <= n * m; i++) {
        // pre[i] means all add_needed before or at index i;
        pre[i] = pre[i - 1] + cnt[i];

        // cnt != 0 means insert needed, hense (m - index + 1) % m is the distance
        if (cnt[i] != 0) dis[(m - (i % m) + 1) % m].insert(i);
    }

    // for any i, just % m can have its place
    // if == 0, it should be at the end
    // cnt[i] means that there are cnt[i] number before it
    // so we need to know whether (pre[i - 1] + i - 1) % m == 0.
    // once any i do not obbey, that means those add_needed cannot be added.
    // Hence, its line whill be replaced with the same. and so the lines below.

    bool flag = false;
    int ans = 0, x = 1;

    for (int i = 0; i < n; i++) {
        if (flag) {
            ans += m; continue;
        }

        int tmp = 0, tmpx = x;
        for (int j = 1; j <= m; j++) {
            int index = i * m + j;
            posi[index] = tmpx; tmpx++;
            if (cnt[index] == 0) {
                continue;
            }
            
            if (j == 1 or pre[index - 1] + index - 1 >= (i + 1) * m) {
                tmp += cnt[index];
            } else {
                // this line should be replaced
                flag = true;
                // okay where is the head
                mark = i * m;
                ans -= (posi[i * m + 1] - 1) % m;
                ans += m;

                // make the ans2 part (from the end to begin)
                for (int k = n * m; k >= posi[i * m] + 1; k--) {
                    ans2.push(make_pair((k - 1) / m, k));
                }

                break;
            }
        }

        for (int j = 1; j <= m; j++) {
            int index = i * m + j;
            x += cnt[index];
            posi[index] = x; x++;
        }

        if (!flag) ans += tmp;
    }

    cout << ans << '\n';

    markChange = false;
    // make a while, !dis[0].empty() is the end of the loop;
    while (!dis[0].empty()) {
        int index = *(dis[0].rbegin());
        dis[0].erase(index);
        f(0, index);
    }

    while(!ans1.empty()) {
        pair<int, int> x = ans1.front(); ans1.pop();
        cout << x.first + 1 << " " << b[x.second] << endl;
    }
    cout << '\n';
    while(!ans2.empty()) {
        pair<int, int> x = ans2.front(); ans2.pop();
        cout << x.first + 1 << " " << b[x.second] << endl;
    }
    cout << '\n';
    while(!ans3.empty()) {
        pair<int, int> x = ans3.front(); ans3.pop();
        cout << x.first + 1 << " " << b[x.second] << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }
    return 0;
}   