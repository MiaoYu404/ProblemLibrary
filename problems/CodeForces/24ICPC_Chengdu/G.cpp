#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int a[N],n;
int res[8*N],tot;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        res[++tot]=a[i];
        if(i==1)continue;
        res[++tot]=a[i-1]&a[i];
        res[++tot]=a[i-1]^a[i];
        res[++tot]=a[i-1]|a[i];
        res[++tot]=(a[i-1]&a[i])^a[i];
        res[++tot]=(a[i-1]&a[i])^a[i-1];
    }
    sort(res,res+tot+1);
    int lastnumber=unique(res,res+tot+1)-res;
    cout<<lastnumber;
}