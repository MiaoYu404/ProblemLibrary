#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;
stack<pair <int, int> > s;
int n[MAXN];

int main(){
    int N; cin >> N;
    memset(n + 1, 0, N);
    for(int i = 1; i <= N; i++)
    {
        int x; cin >> x;
        if(s.empty())
        {
            s.push(make_pair(x, i));
            continue;
        }
        while(!s.empty())
        {
            pair<int, int> y = s.top();
            if(y.first < x)
            {
                n[y.second] = i;
                s.pop();
            }
            else break;
        }
        s.push(make_pair(x, i));
    }

    for(int i = 1; i <= N; i++) cout << n[i] << endl;
    return 0;
}