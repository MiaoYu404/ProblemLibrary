#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 10;
bool mp[N][N];

bool cmp(const int a, const int b) {
    return mp[a][b] ? (a < b) : (a > b);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            for (int j = 0; j < n; j++) {
                mp[i][j + 1] = s[j] - '0';
            }
        }

        vector<int> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(i);
        }
        sort(num.begin(), num.end(), cmp);
        for (auto x : num) {
            cout << x << " " ;
        }
        cout << endl;
    }
}