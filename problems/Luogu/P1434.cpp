// P1434 [SHOI2002] 滑雪
// tags: DFS、记忆化搜索
// 难度：普及/提高-
// link: https://www.luogu.com.cn/problem/P1434

#include <iostream>
#include <math.h>
using namespace std;

int R, C;
int map[105][105][2];

int find(int x, int y){
    if(x < 1 || x > R || y < 1 || y > C) return 0;
    if(map[x][y][1] != 0) return map[x][y][1];
    int val = map[x][y][0];
    int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
    if(val > map[x + 1][y][0]) val1 = find(x + 1, y);
    if(val > map[x - 1][y][0]) val2 = find(x - 1, y);
    if(val > map[x][y + 1][0]) val3 = find(x, y + 1);
    if(val > map[x][y - 1][0]) val4 = find(x, y - 1);
    map[x][y][1] = max(max(val1, val2), max(val3, val4)) + 1;
    return map[x][y][1];
}

int main(){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> map[i][j][0];
        }
    }

    int ans = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(map[i][j][1] == 0) find(i, j);
            if(ans < map[i][j][1]) ans = map[i][j][1];
        }
    }

    cout << ans;

    return 0;
}