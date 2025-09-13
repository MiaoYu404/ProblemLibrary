#include <iostream>
using namespace std;
const int N=2e5+1;
struct node
{
    int l,r;
    int k;
    int leftk,rightk;
    int right_large;
    int left_small;
}t[N*4];
int n,q,a[N],T;
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    t[p].leftk=t[p].rightk=t[p].k=1;
    t[p].right_large=a[r];
    t[p].left_small=a[l];
    if(l==r)return;
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}
void change(int p,int x,int v)
{
    if(t[p].l==t[p].r)
    {
        a[t[p].l]=v;
        t[p].left_small=v;
        t[p].right_large=v;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(x<=mid)change(p*2,x,v);
    else change(p*2+1,x,v);
    t[p].k=min(t[p*2].k,t[p*2+1].k);
    if(t[p*2].right_large<=t[p*2+1].left_small)
        t[p].k=min(t[p].k,t[p*2].rightk+t[p*2+1].leftk);
    else
        t[p].k=min(t[p].k,min(t[p*2].rightk,t[p*2+1].leftk));
    t[p].right_large=t[p*2+1].right_large;
    t[p].left_small=t[p*2].left_small;
    if(t[p*2].leftk==t[p*2].r-t[p*2].l+1&&t[p*2].right_large<=t[p*2+1].left_small)
        t[p].leftk=t[p*2].leftk+t[p*2+1].leftk;
    else t[p].leftk=t[p*2].leftk;
    if(t[p*2+1].rightk==t[p*2+1].r-t[p*2+1].l+1&&t[p*2].right_large<=t[p*2+1].left_small)
        t[p].rightk=t[p*2+1].rightk+t[p*2+1].rightk;
    else t[p].rightk=t[p*2].rightk;

}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(t,0,sizeof(t));
        build(1,1,n);
        cout<<t[1].k<<endl;
        for(int i=1;i<=q;i++)
        {
            int x,v;
            cin>>x>>v;
            change(1,x,v);
            cout<<t[1].k<<endl;
        }
    }
}