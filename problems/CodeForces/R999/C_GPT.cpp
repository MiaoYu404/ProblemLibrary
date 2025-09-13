#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
struct PairHash {
    size_t operator() (const pair<int,int> &st) const {
        return ((size_t)st.first << 20) ^ (size_t)st.second;
    }
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        return a==b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(0);

    int tt; cin >> tt; while(tt--){
        int n; cin >> n;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++){
            int x; cin >> x; a[i] = x;
        }

        unordered_map< pair<int,int>, ll, PairHash > memo;
        memo.reserve(n * 2ull); // 估计可能状态数量

        // dfs
        function<ll(int,int)> dfs = [&](int i, int c)-> ll {
            if(i > n) { return 1LL; }
            auto key = make_pair(i, c);
            if(memo.find(key) != memo.end()){
                return memo[key];
            }
            ll res = 0;
            if(a[i] == c){
                res += dfs(i + 1, c);
                if(res >= MOD) res -= MOD;
            }

            {
                int old_c = c;
                c = old_c + 1;
                if(i == n){
                    res += 1;
                } else {
                    if(a[i + 1] == c){
                        res += dfs(i + 2, c);
                    }
                }
                if(res >= MOD) res %= MOD;
                // c恢复
                c = old_c;
            }

            memo[key] = res;
            return res;
        };

        ll ans = dfs(1, 0) % MOD;
        cout << ans << endl;
    }
    return 0;
}
