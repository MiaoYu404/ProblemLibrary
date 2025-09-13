#include<iostream>
using namespace std;

int z;
int main()
{
    cin >> z;
    while(z--)
    {
        int M;
        cin >> M;
        int H;
        cin >> H;
        int ANS = 0;
        while(H--){
            int a, b;
            cin >> a >> b;
            int ans = 1 % M;
            for(; b; b >>= 1){
                if(b & 1) ans = (long long)ans * a % M;
                a = (long long)a * a % M;
            }
            ANS += ans % M;
            ANS = ANS % M;
        }
        cout << ANS << endl;
    }
    return 0;
} // namespace std;
