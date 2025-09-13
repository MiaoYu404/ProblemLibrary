#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
vector<int> children[N];
bool a[N];

int ans = 0;
int n, d;

void dfs(int x, int dis)
{
    a[x] = true;
    if(dis == d) return;

    for(auto i : children[x])
        if(!a[i])
        {
            dfs(i, dis + 1);
            ans++;
        }
}

int main()
{
    cin >> n >> d;
    memset(a, false, sizeof(a));

    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        children[x].push_back(y);
        children[y].push_back(x);
    }

    dfs(1, 0);

    cout << ans << endl;;
    //for(int i = 1; i <= n; i++) cout << f[i] << " ";
}