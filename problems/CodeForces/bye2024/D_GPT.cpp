#include <bits/stdc++.h>
using namespace std;

// 998244353 是质数
static const int MOD = 998244353;

// --- 快速幂 (在 MOD 下) ---
long long fastPow(long long base, long long exp) {
    long long res = 1 % MOD;
    base %= MOD;
    while(exp > 0) {
        if(exp & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

// --- 乘法逆元 (费马小定理) ---
// x^{-1} mod MOD = x^{MOD-2} mod MOD (MOD 为质数)
long long invMod(long long x) {
    return fastPow(x, MOD - 2);
}

// Fenwicks: 维护频次 FenwFreq 和乘积 FenwProd (皆为 1-based 下标)
struct Fenwicks {
    int n; // Fenwicks 大小（= 离散化后最大坐标）
    vector<long long> fenwFreq;  // 维护频次(加法)
    vector<long long> fenwProd;  // 维护乘积(乘法 mod)

    Fenwicks(int n_) : n(n_), fenwFreq(n_ + 1, 0), fenwProd(n_ + 1, 1) {}

    // 在下标 pos 上加 freqDiff 个元素(此题中 freqDiff 只会是 ±1)
    // val 是该元素的“实际值 mod MOD”
    void update(int pos, long long val, int freqDiff) {
        // 若 freqDiff = +1 就是插入元素 val
        // 若 freqDiff = -1 就是删除元素 val
        long long valPow = (freqDiff > 0 ? val : invMod(val));
        while(pos <= n) {
            fenwFreq[pos] += freqDiff;
            fenwProd[pos] = (fenwProd[pos] * valPow) % MOD;
            pos += (pos & -pos);
        }
    }

    // 求频次前缀和 [1..pos]
    long long prefixFreq(int pos) const {
        long long s = 0;
        while(pos > 0) {
            s += fenwFreq[pos];
            pos -= (pos & -pos);
        }
        return s;
    }

    // 求乘积前缀积 [1..pos]
    long long prefixProd(int pos) const {
        long long p = 1;
        while(pos > 0) {
            p = (p * fenwProd[pos]) % MOD;
            pos -= (pos & -pos);
        }
        return p;
    }
};

// 二分在 Fenwicks 的频次上找：使 prefixFreq(x) >= k 的“最小 x”
// 若找不到(频次总和 < k)，则返回 n+1
int findByOrder(const Fenwicks &fenw, long long k) {
    int pos = 0;
    // 依据 n 最大可到 ~4e5，可以选一个足够覆盖范围的步长
    // 这里用 1<<20(1048576) 足以覆盖到 4e5
    for(int step = 1 << 20; step > 0; step >>= 1) {
        int nxt = pos + step;
        if(nxt <= fenw.n && fenw.fenwFreq[nxt] < k) {
            k -= fenw.fenwFreq[nxt];
            pos = nxt;
        }
    }
    return pos + 1; 
}

// 求 Fenwicks 维护的“前 k 小元素”的乘积 (升序)
long long productOfKSmall(const Fenwicks &fenw, const vector<long long> &idx2val, int k) {
    if(k <= 0) return 1;  // 没有元素可乘，返回乘法单位元
    // 第 k 小元素的坐标 c1 = findByOrder(fenw, k)
    // 这样 prefixFreq(c1) >= k，prefixFreq(c1 - 1) < k
    // 令 c = c1 - 1
    int c1 = findByOrder(fenw, k);
    if(c1 > fenw.n) {
        // 总频次都没到 k，就返回把全部元素都乘上的结果(这里不一定会发生)
        // 不过为了安全，可以把 c1 = fenw.n
        c1 = fenw.n;
    }
    int c = c1 - 1;
    long long totLeft = fenw.prefixFreq(c); // [1..c] 范围内所有元素的频次和
    // 1) [1..c] 坐标都要乘
    long long leftProd = fenw.prefixProd(c);

    // 2) 剩余 r = k - totLeft 个要从坐标 c+1(也就是 c1) 的位置拿
    long long r = k - totLeft;
    if(r <= 0) {
        // 理论上不应出现 r<0 的情况
        return leftProd % MOD;
    }
    if(c1 > fenw.n) {
        // 频次总和都不够 k, 直接返回 leftProd
        return leftProd % MOD;
    }
    // c1 对应的离散值
    long long val = idx2val[c1];
    // 乘上 val^r
    long long part = 1;
    if(val != 0) {
        part = fastPow(val, r);
    }
    long long ans = (leftProd % MOD) * (part % MOD) % MOD;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<long long> A(n), B(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int i = 0; i < n; i++) cin >> B[i];

        // 先把操作读下来，存到数组里
        // 这样我们可以一次性离散化(“离线”处理)
        vector<pair<int,int>> ops(q);
        for(int i = 0; i < q; i++){
            int o, x;
            cin >> o >> x;
            ops[i] = {o, x-1}; // 0-based
        }

        // 收集所有可能的值用于离散化：
        //   A[i], A[i]+最多 q, B[i], B[i]+最多 q
        // 这样写虽然有点浪费，但能保证覆盖范围
        // 如果想更精细，需把每次操作的累加量算进去
        // 这里演示就直接 push_back(A[i], A[i]+q) 这种上界
        vector<long long> allvals;
        allvals.reserve(n*2 + n*2 + q*0); 
        // (最后 *0 是提示：如果要更精确，就把 ops 也拉进来分析)
        for(int i=0; i<n; i++){
            allvals.push_back(A[i]);
            allvals.push_back(A[i] + q);
            allvals.push_back(B[i]);
            allvals.push_back(B[i] + q);
        }
        // 去重 + 排序
        sort(allvals.begin(), allvals.end());
        allvals.erase(unique(allvals.begin(), allvals.end()), allvals.end());
        int m = (int)allvals.size();

        // 构造 Fenwicks
        Fenwicks fenwA(m), fenwB(m);

        // 下标 -> 实际值
        // idx2val[i] = allvals[i-1]
        vector<long long> idx2val(m+1);
        for(int i=1; i<=m; i++){
            idx2val[i] = allvals[i-1];
        }

        // 一个辅助函数，把实际值 v -> 离散化坐标(1-based)
        auto getPos = [&](long long v) {
            int idx = int(std::lower_bound(allvals.begin(), allvals.end(), v) - allvals.begin());
            return idx + 1;
        };

        // 初始化插入
        for(int i=0; i<n; i++){
            int pa = getPos(A[i]);
            fenwA.update(pa, A[i] % MOD, +1);

            int pb = getPos(B[i]);
            fenwB.update(pb, B[i] % MOD, +1);
        }

        // checkP(p): 判断 A_{(p)} <= B_{(p)} 是否成立
        // p=0 视作成立
        auto checkP = [&](int p){
            if(p == 0) return true; 
            // 第 p 小的 A
            int pa = findByOrder(fenwA, p);
            if(pa > m) {
                // A 的频次不够 p 个，无法比较，理论上说明 A_{(p)} > 任何值
                return false;
            }
            long long valA = idx2val[pa];

            // 第 p 小的 B
            int pb = findByOrder(fenwB, p);
            if(pb > m) {
                // B 的频次不够 p 个
                return false;
            }
            long long valB = idx2val[pb];

            return (valA <= valB);
        };

        // 计算当下答案
        auto getAnswer = [&](){
            // 1) 二分找 p \in [0..n]
            int low = 0, high = n;
            while(low < high) {
                int mid = (low + high + 1) >> 1;
                if(checkP(mid)) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }
            int p = low;

            // 2) P = (A 的前 p 小乘积) * (B 的后 n-p 小乘积)
            //    B 的后 n-p 小乘积 = productOfKSmall(B, n) / productOfKSmall(B, p) 
            long long partA = productOfKSmall(fenwA, idx2val, p);
            long long allB  = productOfKSmall(fenwB, idx2val, n);
            long long partB = productOfKSmall(fenwB, idx2val, p);
            long long invPartB = invMod(partB);
            long long tailB = (allB * invPartB) % MOD;

            long long ans = (partA % MOD) * (tailB % MOD) % MOD;
            return ans;
        };

        // 输出初始答案
        {
            long long ans = getAnswer();
            cout << ans;
        }

        // 依次处理每个操作
        for(int i=0; i<q; i++){
            int o = ops[i].first;
            int x = ops[i].second;
            if(o == 1) {
                // a[x] += 1
                int oldPos = getPos(A[x]);
                fenwA.update(oldPos, A[x] % MOD, -1);

                A[x]++;
                int newPos = getPos(A[x]);
                fenwA.update(newPos, A[x] % MOD, +1);
            } else {
                // b[x] += 1
                int oldPos = getPos(B[x]);
                fenwB.update(oldPos, B[x] % MOD, -1);

                B[x]++;
                int newPos = getPos(B[x]);
                fenwB.update(newPos, B[x] % MOD, +1);
            }

            long long ans = getAnswer();
            cout << " " << ans;
        }
        cout << "\n";
    }

    return 0;
}
