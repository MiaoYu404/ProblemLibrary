#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long l, r;
    double p;
    cin >> n >> p >> l >> r;
    double ans = (r - l + 1) * p;
    printf("%.6lf\n", ans);
    return 0;
}