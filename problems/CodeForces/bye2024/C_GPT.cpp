#include <bits/stdc++.h>
using namespace std;

// 为了安全起见，这里用 64 位无符号数来存最终答案。
// 中间乘法用 __int128 做一下乘法保护。
static inline unsigned long long mul128(unsigned long long a, unsigned long long b) {
    __int128 res = ( __int128 ) a * b;
    // 题意的最终结果不会超过 2^63-1，但万一真要更严谨，可在此检测
    // if (res > numeric_limits<unsigned long long>::max()) { ... }
    return (unsigned long long)res;
}

// 返回一个 pair，
//   first  = c(n, k)  （会被瞄到的星星数量）
//   second = f(n, k)  （这些星星的下标之和）
pair<unsigned long long, unsigned long long> solvePair(unsigned long long n, unsigned long long k) {
    // 若长度 < k，直接放弃
    if (n < k) {
        return {0ULL, 0ULL};
    }
    // 偶数长度
    if ((n & 1ULL) == 0ULL) { 
        // n 是偶数
        unsigned long long half = n >> 1; // = n/2
        // 先算出 子区间 的 c 与 f
        auto [c_sub, f_sub] = solvePair(half, k);
        // c(n) = 2 * c_sub
        unsigned long long c_val = 2ULL * c_sub;
        // f(n) = 2*f_sub + (n/2)*c_sub
        // 注意乘法用128保护
        unsigned long long f_val = 2ULL * f_sub + mul128(half, c_sub);
        return {c_val, f_val};
    }
    else {
        // n 是奇数
        unsigned long long p = (n - 1ULL) >> 1;  // (n-1)/2
        auto [c_sub, f_sub] = solvePair(p, k);
        
        // c(n) = 1 + 2*c_sub
        unsigned long long c_val = 1ULL + 2ULL * c_sub;
        
        // f(n) = (中间星) + 2*f_sub + (中间星)*c_sub
        // 中间星下标 = (n+1)/2
        unsigned long long mid = (n + 1ULL) >> 1;
        
        // 先算 (mid)*c_sub 的乘法
        unsigned long long mid_c = mul128(mid, c_sub);
        
        unsigned long long f_val = mid + 2ULL * f_sub + mid_c;
        return {c_val, f_val};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        unsigned long long n, k;
        cin >> n >> k;
        auto [c_ans, f_ans] = solvePair(n, k);
        cout << f_ans << "\n";
    }
    return 0;
}
