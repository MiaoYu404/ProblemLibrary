#include <iostream>
using namespace std;

//bool table[105];

int main(){
    /*
    for(int i = 1; i <= 100; i++) table[i] = false;
    for(int i = 2; i <= 50; i += 2){
        for(int j = 100 - i; j >= 2; j -= 2){
            table[i + j] = true;
        }
    }
    */
    int x = 0;
    cin >> x;
    if(x % 2 == 0 and x != 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}