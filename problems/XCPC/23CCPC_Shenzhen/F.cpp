#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
using ll = long long;
vector<int> e[N];
int n;
int dfn[N],cnt;
int deg[N];
int cnt3, cnt5;
ll ans;
ll cal(int u,int v)
{
    //cout<<u<<' '<<v<<endl;
    int bcnt3=cnt3,bcnt5=cnt5,res;
    if(deg[u]==4)cnt3++;
    if(deg[u]==5)cnt5--;
    if (deg[v] == 4)
        cnt3++;
    if (deg[v] == 5)
        cnt5--;
    if(cnt5!=0)res=0;
    else res=cnt3;
    cnt3=bcnt3;
    cnt5=bcnt5;
    return res;
}
int dfs(int u,int fa)
{
    dfn[u]=++cnt;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        if(dfn[v]!=0)
        {
            ans+=cal(u,v);
            return dfn[v];
        }
        int low = dfs(v, u);
        if (low!= 0)
        {
            ans += cal(u, v);
            if (low == dfn[u])
                return 0;
            return low;
        }
    }
    return 0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if (deg[i] <= 3)
            cnt3++;
        if(deg[i]==5)
            cnt5++;
    }
    dfs(1,0);
    cout<<ans;
}