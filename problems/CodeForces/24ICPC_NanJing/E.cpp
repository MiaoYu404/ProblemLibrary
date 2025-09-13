#include <bits/stdc++.h>
using namespace std;

int judge(char a[], int m, int n){
    int end = 0;
    char nanjing[7] = {'n', 'a', 'n', 'j', 'i', 'n', 'g'};
    for (int j = 0 ; j < m ; j++){
        while (a[j] == nanjing[n]){
            j++;
            n++;
            if (n == 7){
                j--;
                end++;
                break;
            }
        }
        n = 0;
    }
    return end;
}

int main(){
    int T;
    cin >> T;
    char nanjing[7] = {'n', 'a', 'n', 'j','i', 'n', 'g'};
    for (int nmd = 0 ; nmd < T ; nmd++){
        int n, k;
        cin >> n >> k;
        char s[n];
        cin >> s;
    int end = judge(s, n, 0);
    int count1 = 0;
    int count2 = n-1;
    int mid;
    for (int j = 0 ; j < 7 ; j++){
        while (s[0] != nanjing[j]){
            j++;
            if (j == 7){
                break;
            }
        }
        if (j == 7) break;
        if (s[0] == 'n'){
            if (s[1] == 'a') j = 1;
            else if (s[1] == 'j') j = 3;
            else if (s[1] == 'g') j = 6;
            else break;
        }
        mid = judge(s, n, j);
        if (mid == end) break;
        j--;
        count2 -= j;
        while (s[count2] == nanjing[count1]){
            count2++;
            count1++;
            if (count2 == n) break;
        }
        if (count2 != n) break;
        if ((6-count1) <= k)
        end++;
    }
    cout << end << endl;
    }
    return 0;
}