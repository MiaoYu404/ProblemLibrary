// Codeforces Round 1024 (Div. 1) B. Quartet Swapping
// tags: 暴力、数据结构、整除、贪心、排序
// 难度: *1800
// link: https://codeforces.com/contest/2101/problem/B

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 1e9 + 5;

vector<int> trans(vector<int> v) {
    int index = min_element(v.begin(), v.end()) - v.begin();
    vector<int> tmp;
    tmp.assign(v.begin() + index, v.end());
    vector<int> tmp2;
    tmp2.assign(v.begin(), v.begin() + index);
    
    tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
    return tmp;
}

vector<int> getOrder(vector<int> v) {
    // return a order of vector;
    vector<int> ret;
    int minIndex = min_element(v.begin(), v.end()) - v.begin();
    int maxIndex = max_element(v.begin(), v.end()) - v.begin();
    ret.push_back(minIndex);
    ret.push_back(maxIndex);
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i % 2) odd.push_back(x);
        else even.push_back(x);
    }
    if (n % 2) {
        // odd got 1 more
        odd = trans(odd);
        cout << odd[0] << " ";
        odd.assign(odd.begin() + 1, odd.end());

        while (odd.size() > 2) {
            even = trans(even);
            odd = trans(odd);
            cout << even[0] << " " << odd[0] << " ";
            even.assign(even.begin() + 1, even.end());
            odd.assign(odd.begin() + 1, odd.end());
        }

        vector<int> ord = getOrder(even);
        for (auto i : ord) {
            cout << even[i] << " " << odd[i] << " ";
        }
    } else {
        while (odd.size() > 2) {
            odd = trans(odd);
            even = trans(even);
            cout << odd[0] << " " << even[0] << " ";
            odd.assign(odd.begin() + 1, odd.end());
            even.assign(even.begin() + 1, even.end());
        }

        vector<int> ord = getOrder(odd);
        for (auto i : ord) {
            cout << odd[i] << " " << even[i] << " ";
        }
    }
    /*
    if (n >= 8) {
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        for (int i = 0; i < n / 2; i++) {
            cout << odd[i] << " " << even[i] << " ";
        }
        if (n % 2) cout << odd[n / 2 + n % 2] << " ";
    } else {
        
        if (n == 4) {
            // see odd;
            vector<int> ord = getOrder(odd);
            for (auto i : ord) {
                cout << odd[i] << " " << even[i] << " ";
            }
        } else if (n == 5) {
            odd = trans(odd, n / 2 + n % 2);
            vector<int> ord = getOrder(even);
            cout << odd[0] << " ";
            for (auto i : ord) {
                cout << even[i] << " " << odd[i + 1] << " ";
            }
        } else if (n = 6) {
            odd = trans(odd, 3);
            even = trans(even, 3);
            cout << odd[0] << " " << even[0] << " ";

            odd.assign(odd.begin() + 1, odd.end()); // 切片
            even.assign(even.begin() + 1, even.end()); // 切片

            vector<int> ord = getOrder(odd);
            for (auto i : ord) {
                cout << odd[i] << " " << even[i] << " ";
            }
        } else {
            // n == 7
            odd = trans(odd, 4);
            cout << odd[0] << " ";
            odd.assign(odd.begin() + 1, odd.end());
            
            odd = trans(odd, 3);
            even = trans(even, 3);
            cout << even[0] << " " << odd[0] << " ";

            odd.assign(odd.begin() + 1, odd.end()); // 切片
            even.assign(even.begin() + 1, even.end()); // 切片

            vector<int> ord = getOrder(even);
            for (auto i : ord) {
                cout << even[i] << " " << odd[i] << " ";
            }
        }*/
    cout << endl;
}
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}