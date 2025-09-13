#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> sticks(n);
        for(int i = 0; i < n; i++){
            cin >> sticks[i];
        }

        // 1) 统计频次
        unordered_map<long long,int> freq;
        freq.reserve(n);
        freq.max_load_factor(0.7f);
        for(auto &x : sticks){
            freq[x]++;
        }

        // 2) 检查是否有 freq >= 4
        long long fourVal = -1; 
        for(auto &kv : freq){
            if(kv.second >= 4){
                fourVal = kv.first;
                break;
            }
        }
        if(fourVal != -1){
            // 直接输出 4 根相同长度
            cout << fourVal << " " << fourVal << " " 
                 << fourVal << " " << fourVal << "\n";
            continue;
        }

        // 3) 检查是否能组成 (x,x,y,y), x != y
        //   收集所有 freq>=2 的长度
        vector<long long> pairs;
        pairs.reserve(freq.size());
        for(auto &kv : freq){
            if(kv.second >= 2){
                pairs.push_back(kv.first);
            }
        }
        if(pairs.size() >= 2){
            // 找到两种不同长度即可
            // 取前两个不相同的长度
            sort(pairs.begin(), pairs.end());
            long long x = pairs[0];
            long long y = -1;
            for(int i = 1; i < (int)pairs.size(); i++){
                if(pairs[i] != x){
                    y = pairs[i];
                    break;
                }
            }
            if(y != -1){
                cout << x << " " << x << " " << y << " " << y << "\n";
                continue;
            }
            // 如果 pairs 全都相同，那么 freq>=4 的情况在前面已经判过，所以不会到这一步。
        }

        // 4) 现在最多只有一个长度 freq >= 2。找它作为等腰腿 leg
        long long leg = -1;
        for(auto &kv : freq){
            if(kv.second >= 2){
                leg = kv.first;
                break;
            }
        }
        if(leg == -1){
            // 连两条相同长度的棍子都找不到
            cout << -1 << "\n";
            continue;
        }

        // 5) 尝试找两个不同长度 B1, B2 (底边)，满足 B2 - B1 < 2 * leg 并且有足够频次
        //   先收集所有 distinct 长度并排序
        vector<long long> distinctVals;
        distinctVals.reserve(freq.size());
        for(auto &kv : freq){
            distinctVals.push_back(kv.first);
        }
        sort(distinctVals.begin(), distinctVals.end());

        bool found = false;
        // 可以用双指针或二分，这里用双指针演示
        for(int i = 0; i < (int)distinctVals.size() && !found; i++){
            long long B1 = distinctVals[i];
            // 如果 freq[B1] == 0 或 B1 都已经过时也没必要，实际上不会==0，这里只是逻辑检查
            if(freq[B1] < 1) continue;

            // 需要找 B2 > B1，且 B2 - B1 < 2*leg
            // 可以用 upper_bound 找出 B2 < B1 + 2*leg 的最大值索引
            long long limit = B1 + 2LL * leg; // B2 必须严格 < limit
            // upper_bound 找到 >=(B1+2*leg) 的第一个迭代器
            auto it = upper_bound(distinctVals.begin(), distinctVals.end(), limit - 1); 
            // 我们希望下标 it-1 是可能的最大 B2
            if(it == distinctVals.begin()){
                // 没有任何值 < limit
                continue;
            }
            // j 指向候选 B2 的下标
            int j = (int)(it - distinctVals.begin()) - 1;

            // 从大到小尝试
            for(; j > i; j--){
                long long B2 = distinctVals[j];
                if(B2 == B1) continue;  // 要求两条底不同，否则就是矩形/正方形情况，已特判过
                if(freq[B2] < 1) continue;

                long long diff = B2 - B1;  // > 0
                // 对正面积要求：leg > diff/2 => diff < 2*leg(已保证)
                // 检查频次是否够用
                // 1) 如果 B1==leg 且 B2 != leg => freq(leg) 需要 >= 3
                // 2) 如果 B2==leg 且 B1 != leg => freq(leg) 需要 >= 3
                // 3) 如果 B1!=leg 且 B2!=leg => freq(leg) 需要 >= 2
                // 4) B1==leg==B2 => 需要 freq(leg)>=4 (已经特判)
                bool enough = true;
                if(B1 == leg && B2 != leg){
                    if(freq[leg] < 3) enough = false;
                }
                if(B2 == leg && B1 != leg){
                    if(freq[leg] < 3) enough = false;
                }
                // B1 == leg == B2 的情形，上面已经排除过

                if(!enough) continue;

                // 如果都满足，就可以输出
                // 输出顺序：leg, leg, B1, B2
                // 当然也可以先写 B1, B2, 再写 leg, leg，但题目只要求能输出即可
                cout << leg << " " << leg << " " << B1 << " " << B2 << "\n";
                found = true;
                break;
            }
        }

        if(!found){
            cout << -1 << "\n";
        }
    }

    return 0;
}
