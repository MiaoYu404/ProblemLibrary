/*#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N];
int tmp;
int n;
set<ll> vis;

int find(int x, int index) {
    int maxCount = 0;
    int currentCount = 0;

    for (int i = 1; i <= index - 1; i++) {
        if (a[i] == x) {
            currentCount++;
        } else {
            maxCount = max(maxCount, currentCount);
            currentCount = 0;
        }
    }
    // 防止数组以 1 结尾时没有更新最大值
    maxCount = max(maxCount, currentCount);
    currentCount = 0;
    for (int i = index + 1; i <= n; i++) {
        if (a[i] == x) {
            currentCount++;
        } else {
            maxCount = max(maxCount, currentCount);
            currentCount = 0;
        }
    }
    maxCount = max(maxCount, currentCount);
    return maxCount;
}

int main() {
    int tt; cin >> tt; while (tt--) {
        vis.clear(); tmp = 0;
        cin >> n;
        ll num = 0, index = 0;
        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            a[i] = x;
            if (x != 1 and x != -1) num = x, index = i;
        }

        int l1, r1, l2, r2, i1, i2;
        l1 = r1 = l2 = r2 = 0;
        i1 = index - 1;
        i2 = index + 1;

        tmp = 0;
        while (i1 > 0) {
            tmp += a[i1];
            l1 = min(tmp, l1);
            r1 = max(tmp, r1);
            i1--;
        }

        tmp = 0;
        while (i2 < n + 1) {
            tmp += a[i2];
            l2 = min(tmp, l2);
            r2 = max(tmp, r2);
            i2++;
        }

        int minn = find(-1, index) * -1;
        int maxn = find(1, index);
        int l = min(l1, min(l2, l1 + l2));
        int r = max(r1, max(r2, r1 + r2));
        vector<ll> ans;

        for (int i = l; i <= r; i++) {
            if (!vis.count(i + num)) ans.push_back(i + num);
            vis.insert(i + num);
        }
        for (int i = min(minn, min(l1, l2)); i <= max(maxn, max(r1, r2)); i++) {
            if (!vis.count(i)) ans.push_back(i);
            vis.insert(i);
        }

        if(!vis.count(0)) ans.push_back(0);

        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> ans;

void init() {

}

int main () {
    int tt; cin >> tt; while (tt--) {
        
    }
}