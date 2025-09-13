#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;

int bx, by, mx, my;
long long f[maxn][maxn];
bool vis[maxn][maxn];

int main() {
    cin >> bx >> by >> mx >> my;

    vis[mx][my] = true;
    if(mx - 2 >= 0 && my - 1 >= 0) vis[mx - 2][my - 1] = true;
    if(mx - 1 >= 0 && my - 2 >= 0)vis[mx - 1][my - 2] = true;
    if(my - 1 >= 0) vis[mx + 2][my - 1] = true;
    if(my - 2 >= 0) vis[mx + 1][my - 2] = true;
    if(mx - 2 >= 0) vis[mx - 2][my + 1] = true;
    if(mx - 1 >= 0) vis[mx - 1][my + 2] = true;
    vis[mx + 2][my + 1] = true;
    vis[mx + 1][my + 2] = true;

    f[0][0] = 1;
    for (int x = 0; x <= bx; x++) {
        for (int y = 0; y <= by; y++) {
            if(x == 0 && y == 0) continue;
            if(vis[x][y]) continue;
            if(x - 1 >= 0) f[x][y] += f[x - 1][y];
            if(y - 1 >= 0) f[x][y] += f[x][y - 1];
        }
    }

    cout << f[bx][by] << endl;
    /*
    for (int x = 0; x <= bx; x++) {
        for (int y = 0; y <= by; y++)
            cout << f[x][y] << " ";
        cout << endl;}*/
}