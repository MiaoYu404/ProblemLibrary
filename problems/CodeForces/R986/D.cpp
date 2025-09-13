#include <bits/stdc++.h>
using namespace std;

int tt, n;
const int N = 2e5 + 10;
int j[N], q[N], k[N];
pair<int, char> f[N][3];
stack<pair<char, int> > ans;

int main() {
    cin >> tt; while (tt--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            q[i] = x;
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            k[i] = x;
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            j[i] = x;
        }

        f[0][0] = make_pair(q[0], 'q');
        f[0][1] = make_pair(k[0], 'k');
        f[0][2] = make_pair(j[0], 'j');
        for (int i = 0; i < 3; i++) f[n - 1][i] = make_pair(-1, '\0');
        for (int i = 1; i < n; i++) {
            bool exchange = false;
            char from = '\0';
            if (q[i] < f[i - 1][0].first) exchange = true, from = 'q';
            else if (k[i] < f[i - 1][1].first) exchange = true, from = 'k';
            else if (j[i] < f[i - 1][2].first) exchange = true, from = 'j';
            if (exchange) {
                f[i][0] = make_pair(max(q[i], f[i - 1][0].first), from);
                f[i][1] = make_pair(max(k[i], f[i - 1][1].first), from);
                f[i][2] = make_pair(max(j[i], f[i - 1][2].first), from);
            }else {
                if (i != n - 1) {
                    f[i][0] = f[i - 1][0];
                    f[i][1] = f[i - 1][1];
                    f[i][2] = f[i - 1][2];
                }
            }
        }

        if (f[n - 1][0].first != -1) {
            ans.push(make_pair(f[n - 1][0].second, n));
        }else if (f[n - 1][1].first != -1) {
            ans.push(make_pair(f[n - 1][1].second, n));
        }else if (f[n - 1][2].first != -1) {
            ans.push(make_pair(f[n - 1][2].second, n));
        }else {
            cout << "NO" << '\n';
            continue;
        }
        
        cout << "YES" << '\n';
        int from = n - 1, cnt = 0;
        while (from != 0) {
            cnt++;
            char pre = ans.top().first;
            int index = -1;

            if (pre == 'q') index = 0;
            else if (pre == 'k') index = 1;
            else index = 2;

            int l = 0, r = from - 1;
            int mid;
            while (l < r) {
                mid = (l + r) / 2;
                if (f[mid][index].first < f[from][index].first) l = mid + 1;
                else r = mid;
            }
            from = r;
            ans.push(make_pair(f[from][index].second, from + 1));
        }
        ans.pop();
        cout << cnt << '\n';
        while (!ans.empty()) {
            pair<char, int> tmp = ans.top(); ans.pop();
            //if (ans.empty()) break;
            cout << tmp.first << " " << tmp.second << '\n';
        }
    }
    return 0;
}