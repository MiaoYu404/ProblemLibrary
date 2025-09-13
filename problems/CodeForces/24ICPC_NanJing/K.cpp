#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int T,n,k,ans;
char nanjing[7] = {'n', 'a', 'n', 'j', 'i', 'n', 'g'};
char s[N];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        if(n<7)
        {
            cout<<0<<endl;
            continue;
        }
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        for(int i=0;i<=n-7+min(k,6);i++)
        {
            for(int j=0;j<7;j++)
            {
                if(s[(i+j)%n]!=nanjing[j])break;
                if(j==6)ans++;
            }
        }
        cout<<ans<<endl;
    }
}