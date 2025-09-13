#include <iostream>
#include <bits\stdc++.h>
using namespace std;

unordered_map<int, int> lang;

int main()
{
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        lang[x]++;
    }

    int m;
    int mov[200010][2];
    cin >> m;

    for(int i = 1; i <= m; i++){
        int b;
        cin >> b;
        mov[i][0] = lang[b];
    }

    for(int i = 1; i <= m; i++){
        int c;
        cin >> c;
        mov[i][1] = lang[c];
    }

    int max = 0, ans = 0; bool single = true;
    for(int i = 1; i <= m; i++){
        if(mov[i][0] == max){
            single = false;
        }else if(mov[i][0] > max){
            max = mov[i][0], ans = i, single = true;
        }
    }

    if(single){
        cout << ans;
        return 0;
    }
    else{
        int max2 = 0;
        ans = 0;
        for(int i = 1; i <= m; i++){
            if(mov[i][0] < max) continue;
            if(mov[i][1] >= max2){
                max2 = mov[i][1];
                ans = i;
            }
        }
    }
    
    cout << ans;
    return 0;
}