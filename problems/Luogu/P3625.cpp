#include<iostream>
using namespace std;

int M, N, K;
int map[1505][1505], pre[1505][1505];

int main(){
    cin >> M >> N >> K;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + map[i][j];
        }
    }

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}