#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e5 + 10;
int a[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        vector< pair<int, int> > q;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            int l, r; cin >> l >> r;
            if (l == r) a[l]++;
            q.push_back(make_pair(l, r));
        }

        vector <int> num;
        for (int i = 1; i <= 2 * n; i++) {
            if (a[i] == 0) num.push_back(i);
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            pair<int, int> x = q[i];
            if (x.first == x.second) {
                if (a[x.first] > 1) ans = ans + '0';
                else ans += '1';
                continue;
            }
            else {
                int l = 0, r = num.size() - 1;
                int mid, ret = -1;
                while (l <= r) {
                    mid = l + ((r - l) >> 1);
                    if (num[mid] > x.second) r = mid - 1;
                    else if (num[mid] < x.first) l = mid + 1;
                    else {
                        ret = mid;
                        break;
                    }
                }
                if (ret == -1) ans += '0';
                else ans += '1';
            }
        }
        cout << ans << endl;
    }
    return 0;
}