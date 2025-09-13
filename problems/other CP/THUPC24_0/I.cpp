#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD=998244353;
const int N=1e5+10;
int tt,n;
ll f[N];
int main() {
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        int a,b;
        f[0]=1;
        int start;
        int end;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>b;
            if(i<21)
            {
                start=max(0,i-11);
                end=min(i,11);
            }
            else
            {
                start=(i+1)/2-1;
                end=i/2+1;
            }
            //cout<<start<<"->"<<end<<endl;
            if(a==-1&&b==-1)
            {
                f[end]=f[end-1];
                for(int j=end-1;j>=start+1;j--)
                {
                    f[j]=(f[j-1]+f[j])%MOD;
                    //cout<<f[j]<<' ';
                }
                //cout<<endl;
            }
            else
            {
                if(a+b!=i)
                {
                    for(int j=end;j>=start;j--)
                        f[j]=0;
                    continue;
                }
                if(end==a||end==b)
                    f[end]=f[end-1];
                else f[end]=0;
                for(int j=end-1;j>=start+1;j--)
                {
                    if(j!=a&&j!=b)f[j]=0;
                    else f[j]=(f[j-1]+f[j])%MOD;
                    //cout<<f[j]<<' ';
                }
                if(start!=a&&start!=b)
                    f[start]=0;
                //cout<<endl;
            }
        }
        if((n>=21&&n%2==1)||n<11)
                cout<<0<<endl;
            else
                cout<<(f[start]+f[end])%MOD<<endl;
    }
    return 0;
}