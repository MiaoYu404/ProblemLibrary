#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1005;

int n;
int a[N], b[N];

struct op {
    int index, val;
}; vector<op> ops;

void f(int l, int r) {
    if (l >= r) return ;
    // cout << "a " << l << " " << r << endl;
    // cout << endl;
    int mid = (l + r + 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] >= mid && b[i] <= r)
        {
            a[i] += mid - l;
            ops.push_back({2, i});
        }
    }

    for (int k = l + 1; k < mid; k++)
    {
        ops.push_back({1, k});
    }
    f(l, mid - 1);
    f(mid, r);
}

int main () {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; b[i] = x;
    }

    f(0, n);

    // for (int i = 1; i <= n; i++) {
    //     while (a[i] < b[i]) {
    //         ops.push_back({2, i});
    //         a[i]++;
    //     }
    // }

    cout << ops.size() << endl;
    for (op o : ops) {
        cout << o.index << " " << o.val << endl;
    }
}

/*
4
2 4 3 1
*/