#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=310;
const int M=6e4+10;
const ll mod=(ll)(2e10)+33;
int n,q,m,K,csize;
ll hasing[N][1000];
char s[N][M];
int main()
{
    cin>>n>>q>>m>>K;
    csize=sqrt(m*K)+1;
    for(int k=1;k<=n;k++)
    {
        cin >> s[k];
        int ccnt = 0;
        for(int i=0;i<m;i+=csize)
        {
            for(int j=i;j<min(i+csize,m);j++)
            {
                hasing[k][ccnt]=(hasing[k][ccnt]*27+s[k][j]-'a'+1)%mod;
            }
            ccnt++;
        }
    }
    for(int l=1;l<=q;l++)
    {
        cin >> s[0];
        int ccnt = 0;
        for (int i = 0; i < m; i += csize)
        {
            hasing[0][ccnt]=0;
            for (int j = i; j < min(i + csize, m); j++)
            {
                hasing[0][ccnt] = (hasing[0][ccnt]*27 + s[0][j] - 'a' + 1) % mod;
            }
            ccnt++;
        }
        int ans=0;
        for(int k=1;k<=n;k++)
        {
            int dif=0;
            ccnt=0;
            for(int i=0;i<m;i+=csize)
            {
                if(hasing[0][ccnt]!=hasing[k][ccnt])
                {
                    for (int j = i; j < min(i + csize, m); j++)
                    {
                        if(s[k][j]!=s[0][j])
                            dif++;
                        if(dif>K)break;
                    }
                }
                if(dif>K)break;
                ccnt++;
            }
            if(dif>K)continue;
            ans++;
        }
        cout<<ans<<endl;
    }
}
/*
6 4 4 1
kaki
kika
manu
nana
tepu
tero
kaka
mana
teri
anan
*/