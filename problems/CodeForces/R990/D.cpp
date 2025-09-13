#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {scanf("%d", &a[i]);}

    vector<int> front(n);
    multiset<int> last;                                             // 开多元集合，排列 + 允许重复元素
    //定义双指针
    int frontBegin = n;
    int frontEnd = n;

    for (int i = n - 1; i >= 0; i--) {
        // 目的：
        // 防止空位置
        // 或者，元素比front的开头要来的小
        if (frontBegin >= frontEnd || a[i] <= front[frontBegin])
            front[--frontBegin] = a[i];
        else last.insert(a[i] + 1);                                 // 倒置了就得移动

        // 并且last非空（不然无从比较）；
        // 比last中最小值要大（顺序必然颠倒）
        while (frontBegin < frontEnd && !last.empty() && front[frontEnd - 1] > *last.begin()){
            last.insert(front[--frontEnd] + 1);
        }
    }
    vector<int> answer;
    for (int i = frontBegin; i < frontEnd; i++) answer.push_back(front[i]);
    for (auto t : last) answer.push_back(t);
    for (auto t : answer) printf("%d ", t);
    printf("\n");

}
int main() {
    int t;
    cin >> t; while (t--) {
        solve();
    }
    return 0;
}