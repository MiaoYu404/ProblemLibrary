#include <iostream>
#include <math.h>
using namespace std;

void init(){
    
}

int Query(int x);
/*
const int maxn = 1510;

int dp[maxn];//dp表示数量为i个时的最坏情况猜测步数
int pos[maxn]; //当n=i时，最优的起始点位置为pos[i]

void init(){
    
    //100分做法
    dp[0] = 0; dp[1] = 0;
    pos[0] = 0; pos[1] = 1;
    for(int n = 2; n <= 1500; n++)
    {
        //dp.push_back(n); pos.push_back(1);
        dp[n] = n; pos[n] = 1;
        for(int a = 1; a <= n; a++)
        {
            //dp[a] = 1 + (max(dp(a - 1), dp(n - a), log(2)a + log(2)(n-a))
            int x1 = ceil( log2(a) ); int x2 = ceil( log2(n - a + 1) );
            int val = x1 + x2;
            int cost = 1 + max(max(dp[a - 1], dp[n - a]), val);
            if(cost < dp[n]){dp[n] = cost; pos[n] = a;}
        }
    }
    
    //101分做法（太逆天了）
    for(int i = 1; i <= 99; i++){
        int m = 20;
        for(int j = 20; j >= 0; j--) if(pow(2, j) < i){m = j; break;}
        int tmp = pow(2, m-1);
        pos[i] = (i % tmp) + 1;
    }
}
*/


inline int getGuessPosition(int len)// 之前dp我们把在定长中最优的位置找到了；
{
    int i = 0; while(len >> i) ++i;
    return len % (1 << (i - 2));
}

inline pair<int, int> finalGuess(int l, int mid, int r)
{
    int l0, r0, mid0;
    l0 = l, r0 = mid;
    while(r0 > l0)//二分
    {
        mid0 = (l0 + r0) >> 1;
        if(Query(mid0)) l0 = mid0 + 1; else r0 = mid0;
    }
    int a = l0; // a found.

    l0 = mid, r0 = r;
    while(r0 > l0)
    {
        mid0 = (l0 + r0) >> 1;
        if(Query(mid0 + 1)) r0 = mid0; else l0 = mid0 + 1;
    }
    int b = l0; //b found.
    return make_pair(a, b);
}

pair<int, int> guess(int l, int r)
{
    if(l == r) return make_pair(l, r); // 特判
    int posi = l + getGuessPosition(r - l + 1);

    int ret = Query(posi);
    if(ret == -1) return guess(posi + 1, r); // 在posi + 1到r之间猜测。
    if(ret == 0) return finalGuess(l, posi, r); // find in range of [l, posi - 1]
    return guess(l, posi - 1); // find in range of [l, posi - 1];
}

pair<int, int> Guess(int n, int c){
    return guess(1, n);
}

/*
pair<int, int> Guess(int n, int c)
{
    int a, b;
    int l = 1, r = n; int posi = pos[n];
    int res = Query(posi);
    while(res != 0){
        if(res == -1) l = posi + 1;
        else r = posi - 1;

        posi = (l + r) >> 1;
        res = Query(posi);
    }

    //left
    l = 1; r = posi;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(Query(mid) == 0) r = mid;
        else l = mid + 1;
    }
    a = l;

    //right
    l = posi, r = n;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(Query(mid) == 0) l = mid;
        else r = mid - 1;
    }
    b = l;
    return make_pair(a, b);
}
*/
/*
int main(){
    init();
    for(int i = 1; i <= 99; i++){
        cout << pos[i] << " ";
    }
}
*/