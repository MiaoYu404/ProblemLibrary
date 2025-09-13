#include <iostream>
using namespace std;

const int MAXN = 1e2 + 10;

int a[MAXN];

int main(){
    int N; cin >> N;
    int pre = 0;
    for(int i = 1; i <= N; i++)
    {
        int x; cin >> x;
        cout << x - pre << " ";
        pre = x;
    }
}