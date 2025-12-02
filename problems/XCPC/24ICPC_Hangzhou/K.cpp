#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int cntN[N];

int main () {
    ios:: sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int tt; cin >> tt; while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> order;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int p; cin >> p;
                order.push_back(p);
            }
        }

        //if (k >= m) {cout << m << endl; continue;}
        memset(cntN, 0, sizeof(cntN));
        for (int i = 0; i <= n * m - 1; i++) {
            int val = order[i];
            int x = (val - 1) / m, y = val % m;
            cntN[x] ++;
            if (cntN[x] >= m - k) {
                cout << max(i + 1, m) << endl;
                break;
            }
        }
    }
}