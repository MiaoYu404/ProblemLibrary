#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string to_bin(long long n) {
    if (n == 0) return "0";
    string s;
    while (n > 0) {
        s += (n & 1) ? '1' : '0';
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}

long long min_cost(long long a_shift, long long b_shift) {
    long long m = a_shift + b_shift;
    long long cost = 0;
    int bits[64] = {0};
    for (int k = 0; k < 60; ++k) {
        long long bit = 1LL << k;
        if (m >= bit) {
            bits[k] = 1;
            m -= bit;
        } else {
            bits[k] = 0;
        }
    }
    for (int k = 59; k >= 0; --k) {
        if (bits[k]) {
            cost += (1LL << k);
            bits[k] = 0;
            break;
        }
    }
    for (int k = 59; k >= 0; --k) {
        if (bits[k]) {
            cost += (1LL << k);
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long