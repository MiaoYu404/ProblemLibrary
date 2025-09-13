<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;
const int N = 3e5 + 10;
// a: origin, b: target
int a[N], b[N], cnt[N], pre[N], posi[N];

void solve() {
    int n, m; cin >> n >> m;
    
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
        } else {cnt[i]++;}
    }

    pre[0] = 0;
    for (int i = 1; i <= n * m; i++) {
        // pre[i] means all add_needed before or at index i;
        pre[i] = pre[i - 1] + cnt[i];
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
                ans -= (posi[i * m + 1] - 1) % m;
                ans += m;
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

    cout << ans << endl;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;
const int N = 3e5 + 10;
// a: origin, b: target
int a[N], b[N], cnt[N], pre[N], posi[N];

void solve() {
    int n, m; cin >> n >> m;
    
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
        } else {cnt[i]++;}
    }

    pre[0] = 0;
    for (int i = 1; i <= n * m; i++) {
        // pre[i] means all add_needed before or at index i;
        pre[i] = pre[i - 1] + cnt[i];
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
                ans -= (posi[i * m + 1] - 1) % m;
                ans += m;
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

    cout << ans << endl;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        solve();
    }
    return 0;
>>>>>>> e82022ff82b27afda3e03a68bb0e0fef1bc3a311
}   