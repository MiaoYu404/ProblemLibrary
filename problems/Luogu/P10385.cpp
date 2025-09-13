#include <iostream>
using namespace std;

int num[] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans = 0;
int main(){
    for(int i = 2000; i <= 2023; i++){
        for(int j = 1; j <= 12; j++){
            for(int k = 1; k <= day[j - 1]; k++){
                int date = i * 10000 + j * 100 + k;
                int val = 0;
                for(int m = 1; m <= 8; m++){
                    int x = date % 10;
                    val += num[x];
                    date /= 10;
                }
                if(val > 50) ans++;
            }
            if(j == 2 && i % 4 == 0){
                int date = i * 10000 + j * 100 + 29;
                int val = 0;
                for(int m = 1; m <= 8; m++){
                    int x = date % 10;
                    val += num[x];
                    date /= 10;
                }
                if(val > 50) ans++;
            }
        }
    }

    for(int j = 1; j <= 3; j++){
        for(int k = 1; k <= day[j - 1]; k++){
            int date = 2024 * 10000 + j * 100 + k;
            int val = 0;
            for(int m = 1; m <= 8; m++){
                int x = date % 10;
                val += num[x];
                date /= 10;
            }
            if(val > 50) ans++;
        }
        if(j == 2){
            int date = 2024 * 10000 + j * 100 + 29;
            int val = 0;
            for(int m = 1; m <= 8; m++){
                int x = date % 10;
                val += num[x];
                date /= 10;
            }
            if(val > 50) ans++;
        }
    }

    for(int k = 1; k <= 13; k++){
        int date = 2024 * 10000 + 4 * 100 + k;
        int val = 0;
        for(int m = 1; m <= 8; m++){
            int x = date % 10;
            val += num[x];
            date /= 10;
        }
        if(val > 50) ans++;
    }

    cout << ans;
}