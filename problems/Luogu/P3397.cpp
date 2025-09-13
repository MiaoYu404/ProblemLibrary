#include <iostream>
using namespace std;

int map[1010][1010];
int main(){
    int x1, y1, x2, y2;
    int n, m;
    cin >> n >> m;
    while(m--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++)
            for(int j = y1; j <= y2; j++)
                map[i][j]++;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }

    return 0;
}