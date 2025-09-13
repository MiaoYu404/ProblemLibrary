#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

void solve() {
    int n;
    cin >> n;
    
    vector<tuple<char, int, char, int>> gates(n);
    for (int i = 0; i < n; ++i) {
        string l_op, l_a, r_op, r_a;
        cin >> l_op >> l_a >> r_op >> r_a;
        gates[i] = {l_op[0], stoi(l_a), r_op[0], stoi(r_a)};
    }

    vector<pll> states = {{1, 1}};

    for (const auto& [lop, la, rop, ra] : gates) {
        vector<pll> new_states;
        new_states.reserve(states.size() * 2);

        for (const auto& [L, R] : states) {
            // 计算左门增量
            ll A = (lop == '+') ? la : L * (la - 1);
            // 计算右门增量
            ll B = (rop == '+') ? ra : R * (ra - 1);
            ll total = A + B;

            // 生成两种分配方案
            new_states.emplace_back(L + total, R);
            new_states.emplace_back(L, R + total);
        }

        // 立即剪枝：排序后双向过滤
        auto filter = [](vector<pll>& arr) {
            sort(arr.begin(), arr.end(), [](pll a, pll b) {
                return a.first > b.first || (a.first == b.first && a.second > b.second);
            });
            vector<pll> res;
            ll max_r = -1;
            for (auto& p : arr) {
                if (p.second > max_r) {
                    res.push_back(p);
                    max_r = p.second;
                }
            }
            arr.swap(res);
        };

        filter(new_states); // 第一次剪枝：左降序，保留右递增

        // 反向过滤：右降序，保留左递增
        sort(new_states.begin(), new_states.end(), [](pll a, pll b) {
            return a.second > b.second || (a.second == b.second && a.first > b.first);
        });
        vector<pll> filtered;
        ll max_l = -1;
        for (auto& p : new_states) {
            if (p.first > max_l) {
                filtered.push_back(p);
                max_l = p.first;
            }
        }

        // 合并并去重
        states = move(filtered);
        sort(states.begin(), states.end());
        states.erase(unique(states.begin(), states.end()), states.end());
    }

    ll max_sum = 0;
    for (const auto& [L, R] : states) {
        max_sum = max(max_sum, L + R);
    }
    cout << max_sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}