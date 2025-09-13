#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, k, p1, p2;
long long res = 0;
long long val[MAXN];
int to[MAXN];
int head[MAXN];
int nxt[MAXN];
int hv0 = 0;
long long hv[MAXN];//id为i的链的权值和
int bl[MAXN];//节点i所属的重链id

void gethc(int p)
{
    if(head[p]==0)
    {
        bl[p]=++hv0;
        hv[bl[p]]=val[p];
        return;
    }

    int msp = 0;//msp 最大子节点编号
    long long lmc = 0; //lmc 最大子节点对应的重链价值之和
    //遍历子节点
    for(int i=head[p]; i!=0; i=nxt[i])
    {
        //递归
        gethc(to[i]);
        //判断这个节点是不是最大的
        if(lmc<hv[bl[to[i]]])
        {
            lmc=hv[bl[to[i]]];
            msp=to[i];
        }
    }
    bl[p]=bl[msp];
    hv[bl[p]]+=val[p];
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }

    for(int i=1;i<n;i++)
    {
        cin >> p1 >> p2;
        nxt[i]=head[p1];
        head[p1]=i;
        to[i]=p2;
    }
    gethc(1);
    sort(hv+1,hv+hv0+1);
    for(int i=hv0;i >= max(hv0-k+1,1);i--)
        res+=hv[i];
    cout<<res;
}
