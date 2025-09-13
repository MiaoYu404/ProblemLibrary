#include <iostream>
using namespace std;

static const int LEN = 1004;
int a[LEN], b[LEN], c[LEN];

//上高精度

void clear(int a[]) {
  for (int i = 0; i < LEN; ++i) a[i] = 0;
}

void print(int a[]) {
  int i;
  for (i = LEN - 1; i >= 1; --i)
    if (a[i] != 0) break;
  for (; i >= 0; --i) putchar(a[i] + '0');
  putchar('\n');
}

void add(int a[], int b[], int c[]) {
  clear(c);

  // 高精度实现中，一般令数组的最大长度 LEN 比可能的输入大一些
  // 然后略去末尾的几次循环，这样一来可以省去不少边界情况的处理
  // 因为实际输入不会超过 1000 位，故在此循环到 LEN - 1 = 1003 已经足够
  for (int i = 0; i < LEN - 1; ++i) {
    // 将相应位上的数码相加
    c[i] += a[i] + b[i];
    if (c[i] >= 10) {
      // 进位
      c[i + 1] += 1;
      c[i] -= 10;
    }
  }
}

void mul_short(int a[], int b, int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    // 直接把 a 的第 i 位数码乘以乘数，加入结果
    c[i] += a[i] * b;

    if (c[i] >= 10) {
      // 处理进位
      // c[i] / 10 即除法的商数成为进位的增量值
      c[i + 1] += c[i] / 10;
      // 而 c[i] % 10 即除法的余数成为在当前位留下的值
      c[i] %= 10;
    }
  }
}

void cal(int x)
{
    if(x == 1)
    {
        c[0] = 1;
        return ;
    }
    cal(x - 1);
    b[0] = 1;
    mul_short(c, 2, a);
    add(a, b, c);
}

int main(){
    clear(a); clear(b); clear(c);
    int x; cin >> x;
    cal(x);
    mul_short(c, 2, a);
    print(a);
    /*
    ans[1] = 1;
    for(int i = 2; i <= 200; i++){
        ans[i] = 2 * ans[i - 1] + 1;
    }
    int x;
    cin >> x;

    cout << 2 * ans[x];
    */
    return 0;
}