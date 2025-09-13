#include <bits/stdc++.h>
using namespace std;

/*
  我们假设有多组测试，每组的输入为:
    n, k, l
    a1, a2, ..., an
  输出为满足要求的最小时间 * 2（记为 answer），保证是整数。
*/

// 全局常量
static const long long INF = 1e15;

// 读入
// 如果是多组数据，写一个 solve() 循环读取即可。
// 这里演示时假设我们只做一个函数 check(T) 来辅助二分。
long long n, k, L;       // scarecrows 数量, 距离 k, 目标坐标 L
vector<long long> A;     // scarecrows 的初始坐标

// 判断在给定的 2T (即实际时间 T/2 = mid/2) 内，能否把乌鸦推到 >= L
bool canReach(long long doubleTime) {
    // doubleTime = 2 * 实际可用时间
    // 实际可用时间 realT = doubleTime / 2.0
    // 由于题意要输出 2T，因此这里的 doubleTime 就是我们二分的那个 mid
    // scarecrow 的可移动范围是 [a_i - realT, a_i + realT]

    // 1. 计算每个稻草人的可移动区间
    //    由于我们只需要整数比较(题目保证最后结果 * 2 整数)，可以在不影响正确性的前提下，
    //    用整型比较(要小心奇偶问题)。安全做法是用浮点或用分子分母形式。
    //    这里为简单，直接用 long long 并配合 +/-0.5 的技巧或拆分一下。
    //    但是更严谨可使用: left_i = a_i * 2 - doubleTime, right_i = a_i * 2 + doubleTime，
    //    然后在后续比较时同样乘 2 来对齐。下面演示一种写法(乘2存储)。

    vector<pair<long long, long long>> intervals(n);
    // scarecrow 能覆盖的区间用 [L_i, R_i] * 2 表示：
    //    L_i * 2 = (a_i - realT)*2 = 2*a_i - doubleTime
    //    R_i * 2 = (a_i + realT)*2 = 2*a_i + doubleTime
    for(int i = 0; i < n; i++){
        long long left2  = 2LL * A[i] - doubleTime; 
        long long right2 = 2LL * A[i] + 2 * k + doubleTime; 
        intervals[i] = make_pair(left2, right2);
    }

    // 按左端点排序
    sort(intervals.begin(), intervals.end(),
         [](auto &p1, auto &p2){
             return p1.first < p2.first;
         });

    // 2. 贪心地从左到右逼乌鸦前进，乌鸦初始位置 crow = 0
    //    但是这里为了与 intervals 的单位对应一致，我们让 crowPos = crow * 2
    long long crowPos = 0LL;   // 其实就是 2 * 0 = 0
    // 要让乌鸦不断被逼到 >= L (乘2后即 >= L*2)
    long long targetPos = 2LL * L;

    // 我们需要“接力跳”：
    //    当前乌鸦在 crowPos/2，下一次要逼它到 crowPos + 2*k（因为乌鸦一旦被逼，会到 y + k，乘2后就是 y*2 + 2*k）
    //    只要找到一个 scarecrow 能被放到 ≤ crowPos，并且 crowPos - (scarecrow位置*2) < 2*k 即可
    //    等价于 scarecrow位置*2 > crowPos - 2*k
    //    并且 scarecrow位置*2 ≤ crowPos
    //    这个 scarecrow位置*2 必须在它可覆盖区间 [left2, right2] 内
    //
    // 具体实现：每次想“往前逼一步”，指的就是 crowPos += 2*k。
    // 但是前提是我们能在 intervals 里找到一个区间 [L_i, R_i]，可把 scarecrow 放到 [crowPos - 2*k + 1 .. crowPos]
    // (因为 crowPos - (p*2) < 2*k <==> p*2 > crowPos - 2*k )
    // 这里为了不漏任何边界，一般在写程序时要多做一些仔细判断。

    // 或者，也可以一次性看能逼多远：常见做法是“扫描线 + 维护当前能放到 ≤ crowPos 的区间里 scarecrow 能达到的最右 R_i”。
    // 这里简单演示一个“分段跳 k”的思路(可能不够高效，要注意大数据下的优化)。
    
    // 使用一个指针 idx，遍历 intervals
    int idx = 0;
    // 用一个数据结构（这里先用优先队列）来维护所有“左端点 ≤ crowPos” 的区间，根据其右端点R_i排序，看看能否选到合适的 scarecrow
    priority_queue<long long, vector<long long>, std::greater<long long>> pq;

    while (crowPos < targetPos) {
        // 期望下一次“逼”到 crowPos + 2*k
        long long nextPos = crowPos + 2LL*k;

        // 把所有左端点 L_i <= crowPos 的区间都拿进来
        while (idx < n && intervals[idx].first <= crowPos) {
            // intervals[idx] = [L_i, R_i]
            // 只要 R_i >= crowPos - 2*k + 1 之类的即可，有些边界要精细考虑
            // 暂且全扔进优先队列，然后再判断
            pq.push(intervals[idx].second);
            idx++;
        }

        // 从队列里把那些 R_i < crowPos(乌鸦已在 crowPos, scarecrow 如果连 crowPos 都盖不到，就没意义了) 的扔掉
        while(!pq.empty() && pq.top() < crowPos) {
            pq.pop();
        }

        // 此时队列里剩下的区间都是“左端点≤crowPos 且右端点≥crowPos”的
        // 说明可以把 scarecrow 放在 crowPos 这个点或者更左一些(但不会左到逼不动乌鸦)
        // 现在我们一步要跳到 crowPos+2*k，所以只要队列不空就能逼一次
        if (crowPos >= targetPos) return true;
        if(pq.empty()) {
            // 找不到可以卡在 crowPos 左侧且让乌鸦瞬移到 crowPos+k 的稻草人
            return false;
        }

        // 如果能逼一次，就 crowPos = crowPos + 2*k
        crowPos = nextPos;
    }

    return true; // 如果能跳到 >= targetPos，就成功
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // 多组测试
    while(t--){
        cin >> n >> k >> L;
        A.resize(n);
        for(int i=0; i<n; i++){
            cin >> A[i];
        }
        
        // 二分 2T
        long long lo = 0;
        long long hi = 2LL * 100000000; // 或更大一些，反正覆盖到 2*10^8 就行

        while(lo < hi) {
            long long mid = (lo + hi) >> 1; 
            if(canReach(mid)) hi = mid;
            else lo = mid + 1;
        }

        cout << lo << "\n";
    }

    return 0;
}
