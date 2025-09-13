#include <bits\stdc++.h>
using namespace std;

const int maxn = 7 * 1e6 + 5;

long long n, m, k;
double p = 0, s = 0;
double a[maxn];
double minn = 1e21;

long long read(){
    long long x = 0, f = 1;
    char ch = char();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch^48); ch = getchar();}
    return x * f;
}

int main(){
    n = read(), k = read();

    for(int i = 1; i <= n; i++) a[i] = read();
    sort(a + 1, a + n + 1);

    if(a[1] == a[n]){
        printf("No answer!");
        return 0;
    }
}