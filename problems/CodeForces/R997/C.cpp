#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;  // 输入测试用例的数量
    while (T--) {
        int n;
        cin >> n;  // 输入每个测试用例的 n 值
        cout << "1 1 2 ";
        // 3 ~ n - 2
        for (int i = 4; i <= n - 2; i++) {
            cout << i << " ";
        }
        cout << "1 2 " << endl;
    }
    return 0;
}
