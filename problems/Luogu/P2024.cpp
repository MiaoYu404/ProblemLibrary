// P2024 [NOI2001] 食物链
// tags: 并查集
// 难度: 普及+ / 提高
// link: https://www.luogu.com.cn/record/220507601

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ull = unsigned long long;
using ll = long long;

const int MOD = 20000101;
const int N = 5e4 + 10;
int n, k;
int fa[3 * N], from[N], to[N];

int find (int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}

void solve () {
	cin >> n >> k;
	for (int i = 1; i <= 3 * n; i++) fa[i] = i;
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		int opt, x, y; cin >> opt >> x >> y;
		if (x > n or y > n) {ans++; continue;}
		if (opt == 1) {
			if (find(x + n) == find(y) or find(y + n) == find(x)) {ans++;}
			else {
				fa[find(x)] = find(y);
				fa[find(x + n)] = find(y + n);
				fa[find(x + 2 * n)] = find(y + 2 * n);
			}
		} else {
			if (find(x) == find(y) or find(x) == find(y + n)) {ans++;}
			else {
				fa[find(x + n)] = find(y);
				fa[find(x + n + n)] = find(y + n);
				fa[find(x)] = find(y + 2 * n);
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	solve();

	return 0;
}

// 记得开 long long