#include <bits/stdc++.h>
using namespace std;
const __uint128_t Num=1e9;
__uint128_t a,b;
__uint128_t gcd(__uint128_t a,__uint128_t b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
int main() 
{
    int tt; cin >> tt; while(tt--) 
    {
        int a1,b1;
        cin>>a1>>b1;
        a=a1,b=b1;
        int minc=Num;
        int ansd=Num;
        for(__uint128_t pi=1;pi<=Num*Num*Num/b;pi*=2)
        {
            for(__uint128_t pj=1;pj*pi<=Num*Num*Num/b;pj*=5)
            {
                __uint128_t cc=(pi*pj*a-1)/b*b+b-(pi*pj*a);
                __uint128_t cd=pi*pj*b;
                __uint128_t gcdcd=gcd(cc,cd);
                cc/=gcdcd;
                cd/=gcdcd;
                if(minc>=cc)
                {
                    if(minc>cc||cd<ansd)
                    {
                        if(cd>Num)continue;
                        minc=cc;
                        ansd=cd;
                    }
                }
            }
        }
        if(minc==0)ansd=1;
        cout<<minc<<' '<<ansd<<endl;
    }
    return 0;
}