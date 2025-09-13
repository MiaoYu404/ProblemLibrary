#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
    //freopen("5.in", "r", stdin);
    //freopen("5.out", "w", stdout);

    int n, m, t;
    cin >> n >> m >> t;

    bool pos1 = true, pos2 = true;
    if(t % n != 0) pos1 = false;
    if(t % m != 0) pos2 = false;

    int col[100010], row[100010];
    for(int i = 0; i <= n; i++) col[i] = 0;
    for(int i = 0; i <= m; i++) row[i] = 0;

    for(int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        col[x]++, row[y]++;
    }

    //for(int i = 1; i <= n; i++) cout << col[i] << endl;

    if(!pos1 && !pos2){cout << "impossible" << endl; return 0;}

    long long ansCol = 0, ansRow = 0;

    if(pos1){
        long long meanCol = t / n;
        long long prefix[100010];
        for(int i = 0; i <= n; i++) prefix[i] = 0;
        for(int i = 1; i <= n; i++){
            col[i] -= meanCol;
            prefix[i] = prefix[i - 1] + col[i];
        }

        //cout << prefix[n];

        sort(prefix + 1, prefix + 1 + n);

        int k = (n + 1) / 2;

        for(int i = 1; i <= n; i++){
            ansCol += abs(prefix[i] - prefix[k]);
        }
    }

    if(pos2){
        long long meanRow = t / m;
        long long prefix[100010];
        for(int i = 0; i <= m; i++) prefix[i] = 0;
        for(int i = 1; i <= m; i++){
            int val = row[i] - meanRow;
            prefix[i] = prefix[i - 1] + val;
        }

        sort(prefix + 1, prefix + 1 + m);
        
        int k = (m + 1) / 2;

        for(int i = 1; i <= m; i++){
            ansRow += abs(prefix[i] - prefix[k]);
        }
    }

    if(!pos1) cout << "column " << ansCol + ansRow;
    else if(!pos2) cout << "row " << ansCol + ansRow;
    else cout << "both " << ansCol + ansRow;

    return 0;
}