#include <iostream>
#include <stack>
using namespace std;

stack<char> s1;

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i++){
        char x = getchar();
        while(x == ' ' || x == '\n') x = getchar();
        while(x != '\n'){
            if(x - 97 < 26 and x - 97 >= 0){
                // letter
                cout << x;
            }else if(x == ')'){
                //')'
                char y = s1.top(); s1.pop();
                while(y != '('){
                    cout << y;
                    y = s1.top(); s1.pop();
                }
            }else{
                s1.push(x);
            }
            x = getchar();
        }
        while(!s1.empty()) {cout << s1.top(); s1.pop();}
        cout << endl;
    }
}