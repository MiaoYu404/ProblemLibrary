#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000002
ll mod=1000000009;
ll M,K,ln[N],an[N];
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
struct fenshu{
    ll zi,mu;
    friend fenshu operator+(fenshu a,fenshu b){
        ll newzi=a.zi*b.mu+b.zi*a.mu;
        newzi%=mod;
        ll newmu=a.mu*b.mu%mod;
        // ll g = gcd(newzi, newmu);
        // newzi /= g;
        // newmu/=g;

        return (fenshu){newzi,newmu};
    }
    friend fenshu operator+(int a, fenshu b)
    {
        return (fenshu){a,1}+b;
    }
    friend fenshu operator+(fenshu a, int b)
    {
        return (fenshu){b, 1} + a;
    }
    friend fenshu operator*(int a, fenshu b)
    {
        return (fenshu){a, 1} * b;
    }
    friend fenshu operator*(fenshu a, int b)
    {
        return (fenshu){b, 1} * a;
    }
    friend fenshu operator*(fenshu a,fenshu b){
        ll newzi=a.zi*b.zi%mod;
        ll newmu=a.mu*b.mu%mod;
        // ll g = gcd(newzi, newmu);
        // newzi /= g;
        // newmu /= g;
        return (fenshu){newzi,newmu};
    }
}c,d,d1[N],D[N];
ll pow(ll a, ll b, ll p)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

// 快速幂求逆元
ll inverse(int a, int p) { return pow(a, p - 2, p); }

int main(){
    // printf("%lld", 600000038*5ll%mod);
    // cout << qpow(2, 998244353 - 2) * 3 % 998244353;
    scanf("%lld %lld", &M, &K);
    ln[0]=an[0]=1;
    c=d=(fenshu){0,1};
    fenshu m = (fenshu){M, 1};
     for (int i = 1; i <= K; i++)
    {
        
        c=c+m*d+m;
        d=d+(fenshu){M,1+i*(M-1)%mod};
    }
    // printf("%lld %lld\n",c.zi,c.mu);
    printf("%lld",c.zi*inverse(c.mu,mod)%mod);
    
    
}