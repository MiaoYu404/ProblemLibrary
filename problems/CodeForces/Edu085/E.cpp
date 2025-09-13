#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#define MOD 998244353

using namespace std;
using ll = long long;

int u_fac[35], v_fac[35];
ll inverse(ll a) {
	return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inverse(MOD % a) % MOD;
}

vector<ll> facs;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll D; cin >> D;

	ll p = 2;
	while (D != 1 and p <= sqrt(D)) {
		if (D % p == 0) {
			facs.push_back(p);
			while (D % p == 0) D /= p;
		}
		p++;
	}
	if (D != 1) facs.push_back(D);

	int q; cin >> q; while (q--) {
		ll u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		if (u == v) {
			cout << 1 << '\n';
			continue;
		}

		for (int i = 0; i < facs.size(); i++) {
			u_fac[i] = 0;
			while (u % facs[i] == 0) {
				u_fac[i]++;
				u /= facs[i];
			}
		}
		for (int i = 0; i < facs.size(); i++) {
			v_fac[i] = 0;
			while (v % facs[i] == 0) {
				v_fac[i]++;
				v /= facs[i];
			}
		}

		vector<int> del_needed, add_needed;

		int add = 0, minus = 0;
		for (int i = 0; i < facs.size(); i++)
		{
			if (u_fac[i] < v_fac[i]) {
				add_needed.push_back(v_fac[i] - u_fac[i]);
				add += v_fac[i] - u_fac[i];
			}
			else if (u_fac[i] > v_fac[i]) {
				del_needed.push_back(u_fac[i] - v_fac[i]);
				minus += u_fac[i] - v_fac[i];
			}
		}
		
		ll ans = 1;
		if (add_needed.size() > 1) {
			for (int i = 2; i <= add; i++) {
				ans = (ans * i) % MOD;
			}
			for (auto x : add_needed) {
				for (int i = 2; i <= x; i++) {
					ans = ans * inverse(i) % MOD;
				}
			}
		}
		if (del_needed.size() > 1) {
			for (int i = 2; i <= minus; i++) {
				ans = (ans * i) % MOD;
			}
			for (auto x : del_needed) {
				for (int i = 2; i <= x; i++) {
					ans = ans * inverse(i) % MOD;
				}
			}
		}
		cout << ans << '\n';
	}
}