#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m1, m2, s, a[MAXN], sta[MAXN], pop = 0;

void init(){

    memset(a, 0, sizeof(a)); int f = m1;
    for(int i = 2; i <= f; i++){
        if(m1 % i == 0 && !a[i]) pop++, sta[pop] = i;

        while(m1 % i == 0){
            a[i] += m2;
            m1 /= i;
        }
    }
}

int work(int x){
    //判断有多少个质因数
    int sum = 0;
    int f = s;while(f % x == 0) sum++, f /= x;
    return sum;
}

int main(){
    cin >> n >> m1 >> m2;
    //特判
    if(m1 == 1){ cout << "0"; return 0;}
    init(); int ans = MAXN;

    for(int i = 1; i <= n; i++){
        cin >> s; bool flag = true;
        int Max = -1;
        for(int j = 1; j <= pop; j++){
            int k = work(sta[j]);   // 选中一个质因数，并计算数量

            if(!k){flag = false; break;}    //1没有质因数

            if(k >= a[sta[j]]){Max = max(Max, 1);}  //m1没有该质因数/少于s；
            else Max = max(Max, a[sta[j]] / k + (a[sta[j]] % k == 0 ? 0 : 1));  //很好理解 这是一个上取整
        }
        if(flag) ans = min(ans, Max);
    }
    if(ans == MAXN) cout << "-1";
    else cout << ans;
    return 0;
}