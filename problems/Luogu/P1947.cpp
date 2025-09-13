#include <iostream>
using namespace std;

extern "C" int Seniorious(int x);

extern "C" int Chtholly(int n, int c)
{
    int l = 1, r = n;
    while(1){
        int mid = (l + r) >> 1;
        int val = Seniorious(mid);
        if(val == 1){
            r = mid - 1;
        }else if(val == -1){
            l = mid + 1;
        }else{
            return mid;
        }
    }
    return l;
}