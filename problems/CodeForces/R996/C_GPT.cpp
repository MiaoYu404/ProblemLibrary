#include <bits/stdc++.h>
using namespace std;

/*
  我们令所有行、列的最终和都为 0。
  对于非路径格子 (i,j)，直接 b[i][j] = a[i][j] 保持不变。
  对于路径格子 (i,j)，它在初始输入里是 0，需要我们重新赋值。

  主要数据结构/变量：
    - a[i][j]: 输入的高度（对路径格子，为 0；对非路径格子，为原高度）
    - b[i][j]: 输出的高度 (最终结果)
    - rowRemain[i]: 第 i 行尚需分配给“路径格子”的总和(使第 i 行和为 0)
    - colRemain[j]: 第 j 列尚需分配给“路径格子”的总和(使第 j 列和为 0)
    - degRow[i]: 第 i 行在路径上有多少个格子尚未填
    - degCol[j]: 第 j 列在路径上有多少个格子尚未填

  步骤：
    1. 找到路径 (从(0,0)到(n-1,m-1))，记录路径格子标记 isOnPath[i][j] = true。
    2. 统计各行、各列不在路径上的已知和，rowRemain[i] = - sumKnownRow(i)，colRemain[j] = - sumKnownCol(j)。
    3. 统计 degRow[i]、degCol[j] = 该行(列)被路径踩到的格子数。
    4. 用队列维护所有 deg=1 的行/列，弹出后把唯一未知填上、更新相邻的列/行。
*/

static const int64_t INF = 1000000000000000000LL; // just a big number, not crucial here

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // 测试用例数量
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;

        // 读入路径串 s，它长 (n + m - 2)
        // 起点从 (0,0) 出发，根据 s 来走到 (n-1,m-1)
        string s;
        cin >> s;

        // 读入原始海拔 a
        vector<vector<long long>> a(n, vector<long long>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
            }
        }

        // 记录哪些格子在路径上
        vector<vector<bool>> isOnPath(n, vector<bool>(m, false));

        // 路径还原：从(0,0)出发
        {
            int r = 0, c = 0;
            isOnPath[r][c] = true;
            for(char ch : s){
                if(ch == 'R'){
                    c++;
                }else{ // 'D'
                    r++;
                }
                isOnPath[r][c] = true;
            }
        }
        // 现在 (n-1,m-1) 也标为 true

        // 准备输出网格 b，与 a 同尺寸
        // 对于不在路径的格子 b[i][j] = a[i][j]
        // 在路径的格子先填 0，后面再用算法修正
        vector<vector<long long>> b(n, vector<long long>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                b[i][j] = isOnPath[i][j] ? 0LL : a[i][j];
            }
        }

        // 统计每行、每列 不在路径 的和 (便于我们令该行/列的最终和=0)
        // rowRemain[i] = - (不在路径的已知和)
        // colRemain[j] = - (不在路径的已知和)
        vector<long long> rowRemain(n, 0LL), colRemain(m, 0LL);
        for(int i=0;i<n;i++){
            long long sumRow = 0;
            for(int j=0;j<m;j++){
                if(!isOnPath[i][j]){
                    sumRow += a[i][j];
                }
            }
            // 令该行最终和为 0，则“路径格子”总和必须是 -sumRow
            rowRemain[i] = -sumRow;
        }
        for(int j=0;j<m;j++){
            long long sumCol = 0;
            for(int i=0;i<n;i++){
                if(!isOnPath[i][j]){
                    sumCol += a[i][j];
                }
            }
            colRemain[j] = -sumCol;
        }

        // 统计每行/列 被路径踩到的格子个数
        vector<int> degRow(n,0), degCol(m,0);
        // 为了方便快速找到“唯一”的那一个格子，我们存一下行->哪些列(在路径上)，列->哪些行(在路径上)
        vector<vector<int>> row2cols(n), col2rows(m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isOnPath[i][j]){
                    degRow[i]++;
                    degCol[j]++;
                    row2cols[i].push_back(j);
                    col2rows[j].push_back(i);
                }
            }
        }

        // 建立一个队列，先将那些 deg=1 的行/列（只有一个未知数）入队
        // 用一个约定：用正数表示行索引 +1，用负数表示列索引 -1
        //   例如 push(i+1) 表示行 i； push(-(j+1)) 表示列 j
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degRow[i] == 1) q.push(i+1);
        }
        for(int j=0;j<m;j++){
            if(degCol[j] == 1) q.push(-(j+1));
        }

        // BFS 过程：一次只会弹出“度数=1”的行/列
        // 然后确定它唯一的那一个 (i,j) 的值，更新另一个方向
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front > 0){
                // 表示行 i
                int i = front - 1;
                if(degRow[i] != 1) continue; // 有可能被前面操作改动，需判一下
                // 找到该行唯一的路径格子 (i, j)
                int j = -1;
                for(int col : row2cols[i]){
                    if(isOnPath[i][col]){
                        j = col;
                        break;
                    }
                }
                // b[i][j] 就是这整行剩余要分配的 rowRemain[i]
                long long val = rowRemain[i];
                b[i][j] = val;

                // 更新该列
                colRemain[j] -= val; // 已经在该列填进了 val
                degRow[i] = 0; // 该行清零
                rowRemain[i] = 0;
                // 在 (i,j) 被填后，该列 j 的路径格子数减 1
                degCol[j]--;
                // 标记 (i,j) 已经“解决”
                isOnPath[i][j] = false;

                if(degCol[j] == 1){
                    q.push(-(j+1)); 
                }
            }else{
                // 表示列 j
                int j = -front - 1;
                if(degCol[j] != 1) continue;
                // 找到该列唯一的路径格子 (i, j)
                int i = -1;
                for(int row : col2rows[j]){
                    if(isOnPath[row][j]){
                        i = row;
                        break;
                    }
                }
                long long val = colRemain[j];
                b[i][j] = val;

                // 更新该行
                rowRemain[i] -= val;
                degCol[j] = 0;
                colRemain[j] = 0;

                degRow[i]--;
                isOnPath[i][j] = false;

                if(degRow[i] == 1){
                    q.push(i+1);
                }
            }
        }

        // 至此，路径上的所有格子都应该被填完；若还剩下 deg=2 的行/列，一般会在这里也
        // 已经通过互相牵制被定下了值；题目保证可行，不必再做特别处理。

        // 输出结果 b
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << b[i][j] << (j+1<m ? ' ' : '\n');
            }
        }
    }

    return 0;
}
