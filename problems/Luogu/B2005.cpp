#include <iostream>
using namespace std;

int main(){
    char x;
    cin >> x;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= (5 - (2 * i - 1)) / 2; j++)
            cout << " ";
        
        for(int j = 1; j <= (2 * i - 1); j++)
            cout << x;
        
        for(int j = 1; j <= (5 - (2 * i - 1)) / 2; j++)
            cout << " ";
        
        cout << endl;
    }
    return 0;

}