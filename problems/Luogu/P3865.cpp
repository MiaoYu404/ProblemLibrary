#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class SparseTable
{
	using VT = vector<T>;
	using VVT = vector<VT>;
	using func_type = function<T(const T &, const T &)>;

	VVT ST;

	static T default_func(const T &t1, const T &t2) { return max(t1, t2); }

	func_type op;

public:
	SparseTable(const vector<T> &v, func_type _func = default_func)
	{
		op = _func;
		int len = v.size(), l1 = ceil(log2(len)) + 1;
		ST.assign(len, VT(l1, 0));
		for (int i = 0; i < len; ++i)
			ST[i][0] = v[i];
		for (int j = 1; j < l1; ++j)
		{
			int pj = (1 << (j - 1));
			for (int i = 0; i + pj < len; ++i)
				ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
		}
	}
	T query(int l, int r)
	{
		int lt = r - l + 1;
		int q = floor(log2(lt));
		return op(ST[l][q], ST[r - (1 << q) + 1][q]);
	}

	void print() {
		for (auto row : ST)
		{
			for (auto ele : row) cout << ele << " ";
			cout << '\n';
		}
	}
};

int cmp(const int &a, const int &b) { return max(a, b); }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m; cin >> n >> m;
	vector<int> num;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		num.push_back(x);
	}

	SparseTable<int> st(num, cmp);
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << st.query(l - 1, r - 1) << '\n';
	}
}