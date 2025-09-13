#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;
int mp[maxn][maxn];           //0表示无，1表示左下右上，2表示左上右下。
int R, C;
bool vis[maxn][maxn];

//0北 1东 2南 3西
tuple<int, int, int> dir(int come, int mir) {
    if (mir == 0) {
        if (come == 0) return make_tuple(1, 0, 0);
        if (come == 1) return make_tuple(0, -1, 1);
        if (come == 2) return make_tuple(-1, 0, 2);
        if (come == 3) return make_tuple(0, 1, 3);
    }
    else if (mir == 1) {
        if (come == 0) return make_tuple(0, -1, 1);
        if (come == 1) return make_tuple(1, 0, 0);
        if (come == 2) return make_tuple(0, 1, 3);
        if (come == 3) return make_tuple(-1, 0, 2);
    }
    else{ // mir == 2
        if (come == 0) return make_tuple(0, 1, 3);
        if (come == 1) return make_tuple(-1, 0, 2);
        if (come == 2) return make_tuple(0, -1, 1);
        if (come == 3) return make_tuple(1, 0, 0);
    }
}

int cnt, target;
void dfs(int x, int y, int d) {
    if((mp[x][y] == 1 || mp[x][y] == 2) && !vis[x][y]) {cnt++, vis[x][y] = true;}
    tuple<int, int, int> tmp = dir(d, mp[x][y]);
    if(x + get<0>(tmp) <= R && 1 <= x + get<0>(tmp) && y + get<1>(tmp) <= C && 1 <= y + get<1>(tmp))
        dfs(x + get<0>(tmp), y + get<1>(tmp), get<2>(tmp));
    else return;
}

void init() {
    cnt = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            vis[i][j] = false;
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char ch; cin >> ch;
            if (ch == '.') mp[i][j] = 0;
            else if (ch == '/') {mp[i][j] = 1; target++;}
            else {mp[i][j] = 2; target++;}
        }
    }
    int ans = 0;
    vector<string> rsl;
    for (int i = 1; i <= R; i++) {
        init();
        dfs(i, 1, 3);
        if(cnt == target) {ans++; rsl.push_back("W" + to_string(i));}
    }
    for (int i = 1; i <= R; i++) {
        init();
        dfs(i, C, 1);
        if(cnt == target) {ans++; rsl.push_back("E" + to_string(i));}
    }
    for (int i = 1; i <= C; i++) {
        init();
        dfs(1, i, 0);
        if(cnt == target) {ans++; rsl.push_back("N" + to_string(i));}
    }
    for (int i = 1; i <= C; i++) {
        init();
        dfs(R, i, 2);
        if(cnt == target) {ans++; rsl.push_back("S" + to_string(i));}
    }
    cout << ans << '\n';
    for (int i = 0; i < rsl.size(); i++)
        cout << rsl[i] << " ";
}