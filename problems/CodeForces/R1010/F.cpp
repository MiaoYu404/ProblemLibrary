#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500010;
const int MAXM = 1000010;
const int LOGN = 19;

int t, n;
int a[MAXN];
int r[MAXN];
int dp[MAXN];
int st[LOGN][MAXN];

// Build sparse table for range minimum queries
void buildSparseTable() {
    for (int i = 0; i < n; i++) {
        st[0][i] = a[i];
    }
    for (int k = 1; k < LOGN; k++) {
        for (int i = 0; i + (1 << k) <= n; i++) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }
}

// Range minimum query from L to R
int rmq(int L, int R) {
    if (L > R) return INT_MAX;
    int k = 31 - __builtin_clz(R - L + 1);
    return min(st[k][L], st[k][R - (1 << k) + 1]);
}

// Compute r[l]: rightmost position where all elements from l+1 to r[l] are > a[l]
void computeR() {
    for (int l = 0; l < n; l++) {
        int left = l + 1, right = n - 1;
        int res = l;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (rmq(l + 1, mid) > a[l]) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        r[l] = res;
    }
}

// Segment Tree for maximum queries over value domain
struct SegmentTree {
    vector<int> tree;
    int m;

    SegmentTree(int m) : m(m), tree(4 * m, 0) {}

    void update(int idx, int val, int node = 1, int L = 0, int R = -1) {
        if (R == -1) R = m - 1;
        if (L == R) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (L + R) / 2;
        if (idx <= mid) update(idx, val, node * 2, L, mid);
        else update(idx, val, node * 2 + 1, mid + 1, R);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int left, int right, int node = 1, int L = 0, int R = -1) {
        if (R == -1) R = m - 1;
        if (right < L || left > R) return 0;
        if (left <= L && R <= right) return tree[node];
        int mid = (L + R) / 2;
        int p1 = query(left, right, node * 2, L, mid);
        int p2 = query(left, right, node * 2 + 1, mid + 1, R);
        return max(p1, p2);
    }
};

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Build sparse table
    buildSparseTable();

    // Step 2: Compute r array
    computeR();

    // Step 3: Compute dp array using set
    set<int> active;
    for (int j = 0; j < n; j++) {
        while (!active.empty() && r[*active.begin()] < j) {
            active.erase(active.begin());
        }
        if (!active.empty()) {
            dp[j] = j - *active.begin() + 1;
        } else {
            dp[j] = 1;
        }
        active.insert(j);
    }

    // Step 4: Use segment tree to find the answer
    SegmentTree st(MAXM);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int max_left = (a[i] > 1) ? st.query(1, a[i] - 1) : 0;
        int temp = max_left + 1;
        ans = max(ans, temp);
        st.update(a[i], dp[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int test = 0; test < t; test++) {
        solve();
    }
    return 0;
}