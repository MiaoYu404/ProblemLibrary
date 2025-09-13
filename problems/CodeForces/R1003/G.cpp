#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

typedef long long ll;
const int N = 2e5 + 10;
vector<int> p;
int cnt1[N];
int cnt2[N];

bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false; 
    }
    return true;
}
bool isSemiprime(int x) {
    int cnt = 0, tmp = x;
    for (auto x : p) {
        if (tmp == 1) break;
        while (tmp % x == 0) {
            tmp /= x; cnt++;
            if (cnt > 2) return false;
        }
    }
    if (cnt == 2) return true;
    else return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i <= 2e5 + 10; i++) {
        if (isPrime(i)){p.push_back(i);}
    }

    int tt; cin >> tt; while (tt--) {
        int n; cin >> n;
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            if (isPrime(x)) cnt1[x]++;
            else if (isSemiprime(x)) cnt2[x]++;
        }

        u64 ans = 0;

        for (int i = 4; i <= n; i++) {
            // 2 semiprime
            if (cnt2[i] == 0) continue;
            ans += 1LL * cnt2[i] * (cnt2[i] + 1) / 2;

            // 1 semiprime and 1 prime
            for (auto x : p) {
                if (i < x) break;
                if (i % x == 0) ans += 1LL * cnt1[x] * cnt2[i];
            }
        }

        for (int i = 0; i < p.size() and p[i] <= n; i++) {
            //if (p[i] > n) break;
            // 2 primes
            for (int j = i + 1; j < p.size() and p[j] <= n; j++) {
                //if (p[j] > n) break;
                ans += 1LL * cnt1[p[i]] * cnt1[p[j]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}