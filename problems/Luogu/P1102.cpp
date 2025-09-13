#include <iostream>
#include <map>
typedef long long LL;

using namespace std;

map<long long, long long> H;
long long list[200010];

int main(){
    long long N, C;
    cin >> N >> C;

    for(int i = 1; i <= N; i++){
        long long x = 0;
        cin >> x;
        H[x] += 1;
        list[i] = x - C;
    }
    LL cnt = 0;
    for(int i = 1; i <= N; i++) cnt += H[list[i]];

    cout << cnt;
    return 0;
}

/*

#include <iostream>
#include <algorithm>
using namespace std;

long long list[20000000010];

int main(){
    long long N, C;
    cin >> N >> C;

    for(int i = 1; i <= N; i++){
        long long x = 0;
        cin >> x;
        list[i] = x;
    }
    sort(list + 1, list + 1 + N);
    int cnt = 0;
    int a = N - 1, b = N;
    for(b; b >= 2; b--){
        for(a; a >= 1; a--){
            int val = list[b] - list[a];
            if(val == C) cnt++;
            else if (val < C) continue;
            else break;
        }
    }
    cout << cnt;
}
*/