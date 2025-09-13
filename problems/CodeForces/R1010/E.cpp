#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using ll = long long;

const int MOD = 998244353;
const int MAX_BIT = 30;
const ll INV4 = 748683265; // 4^(-1) mod 998244353

// Fast modular exponentiation
ll powmod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// Digit DP to compute sum_{d=0}^{2^30-1} f(d) g(d)
ll compute_sum_fd_gd(int A, int B) {
    vector<int> A_bits(MAX_BIT), B_bits(MAX_BIT);
    for (int i = 0; i < MAX_BIT; i++) {
        A_bits[i] = (A >> i) & 1;
        B_bits[i] = (B >> i) & 1;
    }

    // dp[pos][p][q][r][s]
    vector<vector<vector<vector<vector<ll>>>>> dp(
        MAX_BIT + 1, vector<vector<vector<vector<ll>>>>(
            2, vector<vector<vector<ll>>>(
                2, vector<vector<ll>>(
                    2, vector<ll>(2, 0)
                )
            )
        )
    );

    dp[MAX_BIT][1][1][1][1] = 1;

    for (int pos = MAX_BIT - 1; pos >= 0; pos--) {
        for (int p = 0; p < 2; p++) {
            for (int q = 0; q < 2; q++) {
                for (int r = 0; r < 2; r++) {
                    for (int s = 0; s < 2; s++) {
                        ll val = dp[pos + 1][p][q][r][s];
                        if (val == 0) continue;

                        for (int d_bit = 0; d_bit < 2; d_bit++) {
                            int p_max = p ? A_bits[pos] : 1;
                            for (int p_bit = 0; p_bit <= p_max; p_bit++) {
                                int q_bit = p_bit ^ d_bit;
                                if (q && q_bit > A_bits[pos]) continue;
                                int new_q = q ? (q_bit == A_bits[pos]) : 0;
                                int r_max = r ? B_bits[pos] : 1;
                                for (int r_bit = 0; r_bit <= r_max; r_bit++) {
                                    int s_bit = r_bit ^ d_bit;
                                    if (s && s_bit > B_bits[pos]) continue;
                                    int new_s = s ? (s_bit == B_bits[pos]) : 0;
                                    int new_p = p ? (p_bit == A_bits[pos]) : 0;
                                    int new_r = r ? (r_bit == B_bits[pos]) : 0;
                                    dp[pos][new_p][new_q][new_r][new_s] = 
                                        (dp[pos][new_p][new_q][new_r][new_s] + val) % MOD;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ll sum_fd_gd = 0;
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            for (int r = 0; r < 2; r++) {
                for (int s = 0; s < 2; s++) {
                    sum_fd_gd = (sum_fd_gd + dp[0][p][q][r][s]) % MOD;
                }
            }
        }
    }
    return sum_fd_gd;
}

void solve(int n, int m, int A, int B) {
    ll A_plus_1 = (A + 1) % MOD;
    ll B_plus_1 = (B + 1) % MOD;

    // Precompute powers
    ll two_n = powmod(2, n, MOD);
    ll two_m = powmod(2, m, MOD);
    ll two_n_minus_2 = (two_n - 2 + MOD) % MOD;
    ll two_m_minus_2 = (two_m - 2 + MOD) % MOD;

    // Case 1
    ll binom_B1 = B_plus_1;
    ll binom_B2 = (ll)B * (B + 1) / 2 % MOD;
    ll number1 = A_plus_1 * (binom_B1 + binom_B2 * two_m_minus_2 % MOD) % MOD;

    // Case 2
    ll binom_A1 = A_plus_1;
    ll binom_A2 = (ll)A * (A + 1) / 2 % MOD;
    ll number2 = B_plus_1 * (binom_A1 + binom_A2 * two_n_minus_2 % MOD) % MOD;

    // Overlap
    ll overlap = A_plus_1 * B_plus_1 % MOD;

    // Case 3 using digit DP
    ll sum_fd_gd = compute_sum_fd_gd(A, B);
    ll diff = (sum_fd_gd - overlap + MOD) % MOD;
    ll number3 = (two_n_minus_2 * two_m_minus_2 % MOD * diff % MOD * INV4) % MOD;

    // Total
    ll total = (number1 + number2 - overlap + number3) % MOD;
    if (total < 0) total += MOD;

    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, A, B;
        cin >> n >> m >> A >> B;
        solve(n, m, A, B);
    }

    return 0;
}