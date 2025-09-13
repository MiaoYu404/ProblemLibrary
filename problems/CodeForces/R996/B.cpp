#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll a[N], b[N], dif[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            a[i] = x;
        }
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            b[i] = x;
        }

        int need = 0, minVal = -1;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            int dif = a[i] - b[i];
            if (dif < 0) {
                if (need != 0) {
                    flag = false; break;
                }
                else need = dif;
            } else {
                if (minVal == -1) minVal = dif;
                else minVal = min(minVal, dif);
            }
        }

        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        if (need != 0) {
            if (minVal + need >= 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}