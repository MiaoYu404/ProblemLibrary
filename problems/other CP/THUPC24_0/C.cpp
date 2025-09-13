#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N=1e5+10;

int tt;
int n,x;
int a[N];
int sa[N];
int main() {
    cin>>tt;
    while(tt--)
    {
        cin>>n>>x;
        int ma=0;
        int mi=n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sa[i]=a[i];
            ma=max(a[i],ma);
            if(abs(i-x)>1)
                mi=min(mi,a[i]);
        }
        if(n<=3)
        {
            cout<<ma<<endl;
            continue;
        }
        sort(sa+1,sa+n+1);
        int res=sa[3];
        if(x==1)
            res=max(res,max(min(a[1],a[2]),sa[1]));
        else if(x==n)
            res=max(res,max(min(a[n-1],a[n]),sa[1]));
        else
        {
            ma=0;
            for(int i=x-1;i<=x+1;i++)
                if(a[i]>a[ma])
                    ma=i;
            if(sa[1]<a[ma])a[ma]=sa[1];
            res=max(res,max(a[x-1],max(a[x],a[x+1])));
        }
        cout<<res<<endl;
    }
    return 0;
}