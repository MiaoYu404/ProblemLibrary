#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int maxn = 5e5 + 10;
char s[maxn];
int T;
stack< pair<int, int> > order; //ans顺序

bool judge(){
    int len = strlen(s);
    bool flag = true;
    for(int i = len - 3; i < len; i++) if(s[i] == '-') return false; //头尾正确 

    if(s[0] == '-') return false;

    for(int i = 1; i < len - 3; i++) if(s[i] == '-'){return true;}//存在一个杆子
    return false;
}

int main(){
    cin >> T;
    while(T--){
        cin >> s;
        //cout << strlen(s);
        if(!judge()) {cout << "No" << endl; continue;}

        int len = strlen(s);
        
        //规定箭头的长度为 箭头右侧不包含在箭头里的一点 - 箭头最左侧且在箭头里的一点
        int end = len;
        int m = 0; //统计m

        int e1 = len - 4; //表示第一个是 - 的位置
        for(int i = len - 4; i >= 1; i--) {
            if(s[i] == '-') {break;}
            e1--;
        }

        //知道了-的位置，那么对于任何>e1的就都是>>
        end = e1 + 4;
        for(int i = e1 - 1; i >= 1; i--) {            
            if(s[i] == '-') continue;
            //是'>'
            m++;
            order.push(make_pair(i, end - i));
            end = i + 4; // 设置终点位置，并且可以被覆盖掉
        }

        //输出之前铺设一个底
        m += len - e1 - 3;
        cout << "Yes" << " " << m << endl;

        for (int i = len; i >= e1 + 4; i--)
            cout << 1 << " " << i << endl;
        
        //cout << "e1" << e1 << endl;
        while(!order.empty()){
            pair<int, int> p = order.top();
            order.pop();
            //结果编号由1开始，所以全部+1
            cout << p.first + 1 << " " << p.second << endl; 
        }
    }
}