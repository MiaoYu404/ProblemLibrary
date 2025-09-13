#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//unsigned int 32
const int FULL_MASK = (1u << 30) - 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(0);

    int tt; cin >> tt; while(tt--) {
        int n, m; ll k; cin >> n >> m >> k;

        vector<int> a(n), b(m);
        ll sumA = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[i] = x;
            sumA += a[i];
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            b[i] = x;
        }

        // init
        // B[T] = 所有在 T 中的 b_j 的按位
        // cost[T] = popcount(T).
        int subCnt = (1 << m);
        vector<int> B(subCnt, FULL_MASK);
        vector<int> costT(subCnt, 0);

        // 按位 and 的和
        for(int T = 0; T < subCnt; T++){
            if (T == 0) {
                B[T] = FULL_MASK; 
                costT[T] = 0;
            } else {
                // 找 T 中最高（或最低）的一位 j，然后与 b[j] 再与 B[T\{j}]
                int lowbit = T & (-T);          // 取 T 中最低的 set bit
                int j = __builtin_ctz(lowbit);  // 找到 bit 是第几位
                int Tprev = T ^ lowbit;         // 去掉那一位
                B[T] = B[Tprev] & b[j];
                costT[T] = costT[Tprev] + 1;
            }
        }

        static int best_gain[100001][11]; 
        // init
        for(int i = 0; i < n; i++)
            for(int c = 0; c <= m; c++)
                best_gain[i][c] = 0;


        // 遍历 T
        for(int i = 0; i < n; i++){
            int ai = a[i];
            for(int T = 0; T < subCnt; T++){
                int c = costT[T];
                if (c <= m) {
                    int newVal = ai & B[T];
                    int gain = ai - newVal;

                    best_gain[i][c] = max(gain, best_gain[i][c]);
                }
            }
        }

        // 贪心增量
        // 构造所有 increase_{i,c} = best_gain[i][c] - best_gain[i][c - 1]
        // （c = 1..m），放进一个数组并排序
        vector< tuple<int, int, int> > increments; 
        increments.reserve(n * m);

        for(int i = 0; i < n; i++){
            for(int c = 1; c <= m; c++){
                int d = best_gain[i][c] - best_gain[i][c - 1];
                if(d > 0) {
                    increments.push_back({d, i, c});
                }
            }
        }

        // 按照 d 从大到小排序
        sort(increments.begin(), increments.end(), 
                [](auto &u, auto &v){
                    return get<0>(u) > get<0>(v); 
                }
            );

        // cost_assigned[i] 表示分配给 a[i] 的实际操作数
        vector<int> cost_assigned(n, 0);
        ll used = 0; 
        ll tot = 0;

        for(auto &inc: increments) {
            int d = get<0>(inc);
            int i = get<1>(inc);
            int c = get<2>(inc);
            // if 当前元素的花费正好是 c - 1，才能升到 c
            if(cost_assigned[i] == c - 1 && used < k) {
                cost_assigned[i] = c;
                used += 1;
                tot += d;
                if(used == k) break; // 花光啦
            }
        }

        // 结果 = sumA - tot
        ll ans = sumA - tot;
        cout << ans << "\n";

    } // end while(t--)

    return 0;
}
