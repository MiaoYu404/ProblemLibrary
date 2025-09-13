#include <iostream>
#include <vector>

using namespace std;

const int 5e5 + 10;
int n;
vector<int> c[N];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        c[a].push_back(b);
        c[b].push_back(a);
    }
    return 0;
}