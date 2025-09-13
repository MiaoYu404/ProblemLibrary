#include <iostream>
#include <cmath>
using namespace std;

int N, M, Q;
char map[1005][1005];
int prefix[1005][1005][30];

int solve(int x, int y){
    int val = map[x][y] - 'a';
    int ans = 1;
    int length = min(min(x - 1, N - x), min(y - 1, M - y));
    for(int i = 0; i <= length; i++){
        int tar = (2 * i + 1) * (2 * i + 1);
        int rsl;
        rsl = prefix[x + i][y + i][val] - prefix[x - i - 1][y + i][val] - prefix[x + i][y - i - 1][val] + prefix[x - i - 1][y - i - 1][val];
        if(rsl == tar) ans = max(ans, 2 * i + 1);
        else break;
    }
    return ans;
}

void init(){
    for(int a = 0; a < 26; a++){
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++){
                prefix[i][j][a] = prefix[i - 1][j][a] + prefix[i][j - 1][a] - prefix[i - 1][j - 1][a];
                if(map[i][j] - 'a' == a) prefix[i][j][ map[i][j] - 'a' ]++;
            }
    }
}

int main(){
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }

    init();

    /*
    for(int a = 0; a <= 2; a++){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << prefix[i][j][a] << " ";
        }
        cout << endl;
    }cout << endl;}
    */
    
    while(Q--){
        int x, y;
        cin >> x >> y;
        x++, y++;
        cout << solve(x, y) << endl;
    }
    return 0;
}