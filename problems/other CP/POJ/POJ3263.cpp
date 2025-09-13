#include <iostream>
#include <map>

using namespace std;

int n, h, I, r;
map<pair<int, int>, bool> existed;

int main()
{
    cin >> n >> I >> h >> r;
    int c[10010], d[10010];
    while(r--)
    {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(existed[make_pair(a, b)]) continue;
        d[a + 1] += -1, d[b] += 1;
        existed[make_pair(a, b)] = true;
    }

    for(int i = 1; i <= n; i++){
        c[i] = c[i - 1] + d[i];
        cout << h + c[i] << endl;
    }
}