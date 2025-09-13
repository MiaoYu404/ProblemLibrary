#include <bits/stdc++.h>
using namespace std;

/*
  帮助函数：将字符串拆成 blocks: 返回 (bit, length) 的列表
  例如 s="0001100" -> [(0,3), (1,2), (0,2)]
*/
vector<pair<int,int>> getBlocks(const string &s) {
    vector<pair<int,int>> blocks;
    int n = (int)s.size();
    int start = 0;
    while(start < n) {
        int bit = s[start] - '0';
        int length = 1;
        int j = start + 1;
        while(j < n && s[j] == s[start]) {
            length++;
            j++;
        }
        blocks.push_back({bit, length});
        start = j;
    }
    return blocks;
}

/*
  Fenwick 树 (Binary Indexed Tree) 用于统计逆序对的一个实现
  因为我们要对"块下标"做离散化/本身已经是 0..m-1，所以可直接用 Fenwick 计数
*/
struct Fenwick {
    int n;
    vector<long long> fenw;
    Fenwick(int n) : n(n), fenw(n+1,0LL) {}

    void update(int i, long long val){
        // Fenwick树一般从1开始索引，这里把 i+1 当作Fenw索引
        for(++i; i<=n; i+=(i & -i)){
            fenw[i]+=val;
        }
    }
    long long query(int i){
        // 返回 [0..i] 区间和
        long long s=0;
        for(++i; i>0; i-=(i & -i)){
            s+=fenw[i];
        }
        return s;
    }
    long long rangeQuery(int l,int r){
        if(r<l) return 0;
        return query(r)-query(l-1);
    }
};

/*
  计算一个排列 perm 的逆序对数量，perm 里元素范围 0..(m-1)
  用 Fenwick 树 O(m log m)
*/
long long inversionCount(const vector<int> &perm) {
    int m = (int)perm.size();
    Fenwick fenw(m);
    long long inv = 0;
    // 从左往右，依次把 perm[i] 插入 Fenw，统计有多少已插入元素 > perm[i]
    for(int i=0; i<m; i++){
        int x = perm[i];
        // 查询区间[x+1..m-1] 的数量
        long long bigger = fenw.rangeQuery(x+1, m-1);
        inv += bigger;
        // 在树中标记 x
        fenw.update(x, 1);
    }
    return inv;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 测试次数
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        int n = (int)s.size();
        // 1) 若 0/1 数量不同，直接 -1
        int c0s = int(count(s.begin(), s.end(), '0'));
        int c1s = n - c0s;
        int c0t = int(count(t.begin(), t.end(), '0'));
        int c1t = n - c0t;
        if(c0s != c0t || c1s != c1t){
            cout << -1 << "\n";
            continue;
        }

        // 拆块
        auto bs = getBlocks(s); 
        auto bt = getBlocks(t);

        // 如果整串都只有一种字符，特判一下 (其实下面流程也能处理)
        if(bt.size() == 1){
            // 说明 t 是全 0 或全 1，看 s 是否也仅有一块
            // 只要 0/1 数量对上了，就不需要交换，答案 0
            // (或 s 也仅一块，肯定不用换)
            if(bs.size() == 1) {
                // 已经匹配
                cout << 0 << "\n";
            } else {
                // s 虽然也都是同一个字符，但可能分成多块 (例: "000|000") 
                // 仍然可以全部合并成一块，不需要任何相邻块交换 (因为我们只要把相同块们都合并即可)
                // 实际上，如果 s 有多块，但全是同一个 bit，要合并成一块只需若干相邻块交换吗？
                // 其实把这些块都向一起移动，可能需要若干次 swap。但如果 t 就是一整块，那么
                // 我们的最终顺序只是一块，也无所谓顺序……让我们算一下逆序对即可。
                // 不过这里也可以直接给出答案：最坏要把所有块都并成一块，把 (m-1) 个块依次冒泡到一起，
                // 但所有块 bit 相同，交换顺序其实无效，因为交换两块同 bit 不改变字符串……
                // 但是题目示例也表明：当合并的是同一 bit 的相邻块，交换并不会改变字符串；要想真正“并”它们，必须把它们移到相邻处。不过它们已经是相邻块了(因为别的bit无法插进来)，交换同bit块也不会改变顺序…… 
                // 其实仔细看，若 s 有多块但全 0，跟 t=全0，不需要任何真正的 swap，就已经相等(因为无论那些块怎么分段，拼起来都是同一个字符串"000..."). 
                // 因此答案是 0。
                cout << 0 << "\n";
            }
            continue;
        }

        // 2) 检查块数可否匹配
        //    对于 bit=0 或 bit=1, 如果 t 中有 X 个该 bit 块，则 s 中必须至少有 X 个同 bit 块(才能选不同的 s块 去对应 t 的不同块)。
        //    否则 -1
        //    同时还要能“凑齐”每个块的长度。(把若干 s块 之和 = t块 的长度)
        // 先统计 s与t 每个bit的块信息
        vector<int> s0_idx; // 存 s 中所有 bit=0 的块下标
        vector<int> s1_idx; // 存 s 中所有 bit=1 的块下标
        vector<int> s0_len;
        vector<int> s1_len;
        for(int i=0; i<(int)bs.size(); i++){
            if(bs[i].first == 0){
                s0_idx.push_back(i);
                s0_len.push_back(bs[i].second);
            } else {
                s1_idx.push_back(i);
                s1_len.push_back(bs[i].second);
            }
        }
        vector<int> t0_len, t1_len; // 仅存各 0块、1块的长度
        // 但还需要记录 t 中块的顺序(0块 or 1块)，以便最终拼 permutation
        vector<pair<int,int>> tBlocks; 
        // tBlocks[j] = (bit, length)
        // 这样我们就能知道 t 第 j 块是啥 bit、长度多少
        for(auto &p: bt){
            tBlocks.push_back(p);
            if(p.first==0) t0_len.push_back(p.second);
            else t1_len.push_back(p.second);
        }
        // 数量检查
        int cnt0_s = (int)s0_idx.size(); 
        int cnt1_s = (int)s1_idx.size();
        int cnt0_t = (int)t0_len.size();
        int cnt1_t = (int)t1_len.size();
        if(cnt0_s < cnt0_t || cnt1_s < cnt1_t){
            cout << -1 << "\n";
            continue;
        }

        // 再做“分段匹配检查”：对 0块，能否按顺序凑出 t0_len 里每一段的长度
        // 同理对 1块。只要能把 s 的 0块长度们分为 cnt0_t 组，每组和 t0_len[j] 相等即可
        auto checkPartition = [&](const vector<int> &srcLen, const vector<int> &dstLen){
            // srcLen: s中所有该bit块的长度
            // dstLen: t中所有该bit块的目标块长度
            // 用双指针贪心
            int p = 0; 
            for(int need : dstLen){
                int sum = 0;
                while(p<(int)srcLen.size() && sum<need){
                    sum += srcLen[p++];
                }
                if(sum != need) {
                    return false; // 要么凑不够就截止了，要么凑过头了
                }
            }
            // 必须把 srcLen 恰好用完，否则多出来也无法匹配
            if(p != (int)srcLen.size()) return false;
            return true;
        };
        if(!checkPartition(s0_len, t0_len) || !checkPartition(s1_len, t1_len)){
            cout << -1 << "\n";
            continue;
        }

        // 若通过，说明在长度上也能一一分组成功 -> 可行
        // 3) 生成目标排列 finalOrder：表示在最终字符串里，各个“s的块下标” 出现的顺序
        //    然后统计和原顺序 [0,1,2,...,bs.size()-1] 相比需要多少相邻交换(即逆序对数)
        // 先用相同的分组逻辑，依次取出具体哪些 s块 构成 t 的第 j 块
        // 我们要做的是：t 第 j 块(bit, length) -> 在 s 的未分配的同bit块中，依次拿若干块使长度之和 = length
        // 按拿的顺序，将这些块的下标 append 到 finalOrder
        // note: “拿的顺序” 就是从左往右扫描 s0_idx 或 s1_idx，但**真正放到 finalOrder 里**的顺序，就是 t 第 j 块出现的位置。

        // 做一个辅助函数，把 src(若干块下标 & 块长度) 按顺序分成多段，每段之和 = dstLen[i]，并把对应的下标顺次写入到 out。
        // out 就代表按照 t的顺序排下去的 块下标序列
        auto partitionCollect = [&](const vector<int> &idxArr, const vector<int> &lenArr,
                                   const vector<int> &needArr, vector<int> &out){
            int p = 0;
            for(int need : needArr){
                int sum = 0;
                int startp = p;
                while(sum < need){
                    sum += lenArr[p];
                    // 同时把对应的下标写入 out
                    out.push_back(idxArr[p]);
                    p++;
                }
            }
        };

        // 分别构造 0块、1块 在最终串的顺序
        vector<int> finalOrder_0, finalOrder_1;
        partitionCollect(s0_idx, s0_len, t0_len, finalOrder_0);
        partitionCollect(s1_idx, s1_len, t1_len, finalOrder_1);

        // 现在我们要按照 tBlocks 的顺序，依次从 finalOrder_0 或 finalOrder_1 中“取块”。
        // 由于我们在 partitionCollect 时，0块全部连在一起、1块全部连在一起，但 tBlocks 可能是(0,L1), (1,L2), (0,L3)...
        // 因此我们需要再一次用类似的贪心读法，来真正生成完整的 finalOrder(大小 = bs.size())。
        // 具体做法：
        //   针对 bit=0 的 t块，我们要从 finalOrder_0 顺次取出若干 s块下标(合并成那一块)，数量对应 t0_len 的块数。我们事先知道 t0_len.size()=cnt0_t 块，
        //   同理 bit=1 的也要从 finalOrder_1 顺次取出。这里要记录一下每个 t块需要多少个 s块(在 partitionCollect 里其实也能推算)。
        //   最简单：我们再搞一个指针0_ptr, 1_ptr 指向 finalOrder_0, finalOrder_1 的下一个未用位置，然后 tBlocks 依次看 bit=?
        //   如果 bit=0，就继续“拿”若干下标，直到长度之和 = tBlocks[j].second。这里还得知道 finalOrder_0 里每块下标对应 bs[ thatIndex ].second 的长度
        //   这样就能知道要多少 s块来凑 tBlocks[j].second 。
        
        // 为了方便，这里我们先把 finalOrder_0 转换成 (下标, length) 形式
        // 然后就可以像上面分组一样，对 tBlocks 的一块长度用若干 (下标, length) 来凑
        vector<pair<int,int>> v0, v1;
        {
            // finalOrder_0 里放的是下标，长度可以从 bs[..].second 取
            for(int id: finalOrder_0) {
                v0.push_back({id, bs[id].second});
            }
            for(int id: finalOrder_1) {
                v1.push_back({id, bs[id].second});
            }
        }
        
        vector<int> finalOrder; 
        finalOrder.reserve(bs.size()); // 最终大小就等于 s 的块数
        int p0 = 0, p1 = 0; // 指向 v0,v1
        for(auto &tb: tBlocks){
            int need = tb.second; // 该块长度
            if(tb.first == 0){
                int sum=0;
                while(sum < need){
                    sum += v0[p0].second;
                    finalOrder.push_back(v0[p0].first);
                    p0++;
                }
            } else {
                int sum=0;
                while(sum < need){
                    sum += v1[p1].second;
                    finalOrder.push_back(v1[p1].first);
                    p1++;
                }
            }
        }
        // 此时 finalOrder 就是目标排列(块下标顺序)
        // 计算它与 [0..bs.size()-1] 之间的逆序对
        // 原始顺序就是 0,1,2,...,bs.size()-1
        // finalOrder[i] 中存的值是“块 i 在最后排在什么原索引”。
        // 但统计逆序对，需要把 "finalOrder" 视为一个长度 m=bs.size() 的排列，元素取值也是 0..m-1。
        // 可是现在 finalOrder[i] ∈ [0..m-1] 正好就是 s块在原来顺序的下标。
        // 所以 finalOrder 本身就可以直接拿去做“求逆序对”。
        // 如果 finalOrder = [2,0,1] ，表示最终顺序是原先的块 2 在最前、块0 次之、块1 最后，
        // 逆序对个数即 = 在下标序列 (2,0,1) 里，有多少 (i<j && finalOrder[i] > finalOrder[j])。
        long long ans = inversionCount(finalOrder);
        cout << ans << "\n";
    }

    return 0;
}
