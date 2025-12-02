#include<bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,c[N],cnt[N],lg[N],m1,b1;
void deal(){
    scanf("%d",&n);
    m1=0,b1=-1;
    for(int i=1;i<=n;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%d", c + i);
        cnt[c[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(lg[cnt[i]]>b1){
            b1=lg[cnt[i]];
            m1=i;
        }else if(lg[cnt[i]]==b1){
            m1=-1;
        }
    }
    if(m1==-1){
        // cout<<'u';
        printf("%d\n",(1<<(b1+1))-1);
    }else{
        // cout<<'y';
        int ans=cnt[m1];
        for(int i=1;i<=n;i++){
            if(i==m1)continue;
            int it=(1<<b1);
            for(int j=b1-1;j>=0;j--){
                if (((cnt[m1] >> j) & 1) && ((cnt[i] >> j) & 1)){
                    it|=(1<<(j+1))-1;
                    break;
                }else{
                    it|=(1<<j)&(cnt[m1]|cnt[i]);
                }
            }
            ans = max(ans, it);
            // printf("%d %d %d----\n",i,ans,it);
        }
        printf("%d\n",ans);
    }
}
int main(){
    for(int i=2;i<=100000;i++){
        lg[i]=lg[i>>1]+1;
    }
    scanf("%d",&T);
    while(T--){
        deal();
    }
}