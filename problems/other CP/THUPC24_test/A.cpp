#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
int n,q,ans;
stack<int> ls[N];
int pairs[N];
int c[N],res[N];
bool a[N];
int il[N];
int ta[N];
void add(int x)
{
    if(x==0)return;
    for(int i=x;i<=n;i+=i&-i)
        ta[i]++;
    return;
}
int get(int x)
{
    int tres=0;
    for(int i=x;i>0;i-=i&-i)
        tres+=ta[i];
    return tres;
}
struct query
{
    int l,r,n;
    bool operator<(const query& a) const
    {
        return r==a.r?l<a.l:r<a.r;
    }
}qs[N];

int main() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)ls[c[i]].push(i);
        else if(!ls[c[i]].empty())
        {
            pairs[i]=ls[c[i]].top();
            ls[c[i]].pop();
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>qs[i].l>>qs[i].r;
        qs[i].n=i;
    }
    sort(qs+1,qs+q+1);
    int last=0;
    for(int i=1;i<=q;i++)
    {
        while(last<qs[i].r)
        {
            last++;
            add(pairs[last]);
        }
        res[qs[i].n]=get(last)-get(qs[i].l-1);
    }
    for(int i=1; i<=q; i++)
        cout<<res[i]<< '\n';

    return 0;
}