#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N=1e5+10;
int n;
ll H;
struct gr
{
    double u;
    bool gri;
    int num;
}a[N];
int resn[N];
bool cmp1(gr a,gr b)
{
    return a.u==b.u?a.num<b.num:a.u>b.u;
}
bool cmp(gr a,gr b)
{
    double aa=a.u/pow(2,resn[a.num]),ba=b.u/pow(2,resn[b.num]);
    if(aa==ba)
    {
        if(a.gri==b.gri)
        {
            if(a.u==b.u)
            {
                return a.num<b.num;
            }
            else
            {
                return a.u>b.u;
            }
        }
        else
        {
            return a.gri<b.gri;
        }
        
    }
    else
    {
        return aa>ba;
    }
}
int gett(double x,double t)
{
    int l=0,r=35;
    int mid;
    while(l!=r)
    {
        mid=(l+r)/2;
        if(x/pow(2,mid)<=t)r=mid;
        else l=mid+1;
    }
    return l;
}
int main() {
    cin>>n;
    cin>>H;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].u;
        a[i].num=i;
        a[i].gri=0;
    }
    sort(a+1,a+n+1,cmp1);
    int l=1,r=n;
    int mid;
    int res=0;
    while(l!=r&&l!=n+1)
    {
        mid=(l+r+1)/2;
        res=0;
        for(int i=1;i<=mid;i++)
            res+=gett(a[i].u,a[mid].u);
        if(res>H) r=mid-1;
        else l=mid;
    }
    int tot=0;
    for(int i=1;i<=l;i++)
    {
        res=gett(a[i].u,a[l].u);
        if(res!=0)
            a[i].gri=1;
        resn[a[i].num]=res;
        tot+=res;
    }
    sort(a+1,a+n+1,cmp);
    //for(int i=1;i<=n;i++)cout<<resn[i]<<' ';
    //cout<<endl;
    //for(int i=1;i<=n;i++)cout<<a[i].u/pow(2,resn[a[i].num])<<' ';
    //cout<<(a[2].u<a[3].u)<<cmp(a[2],a[3]);
    //cout<<endl;
    H-=tot;
    //cout<<H;
    for(int i=1;i<=n;i++)
    {
        resn[a[i].num]+=H/n;
        if(i<=H%n)resn[a[i].num]++;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<resn[i]<<' ';
    }
    cout<<endl;
    return 0;
}