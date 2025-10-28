#include <iostream>
#define long long ll
#define MOD 1e9 + 7;

using namespace std;

const int N = 3e2 + 10;

ll f[N][3][N][N];
ll pre[N][N][N];

char s[N];

void init()
{
    for (int i = 1; i <= 300; i++)
    {
        for (int a = 0; a <= 300; a++)
        {
            for (int b = 0; b <= 300; b++)
            {
                for (int c2 = 0; c2 <= 2; c2++)
                {
                    if (s[i - 1] == '?')
                        for (int c = 0; c <= 2; c++)
                        {
                            if (c2 == c)
                                continue;

                            f[i][c][a][b] = f[i - 1][c2][a][b];
                            if (a - 1 >= 0)
                                f[i][c][a][b] = (f[i][c][a][b] + f[i - 1][c2][a - 1][b]) % MOD;
                            if (b - 1 >= 0)
                                f[i][c][a][b] = (f[i][c][a][b] + f[i - 1][c2][a][b - 1]) % MOD;
                        }
                    else
                    {
                        f[i][s[i - 1] - 'a'][a][b] = f[i - 1][c2][a][b];
                        if (a - 1 >= 0)
                            f[i][s[i - 1] - 'a'][a][b] = (f[i][s[i - 1] - 'a'][a][b] + f[i - 1][c2][a - 1][b]) % MOD;
                        if (b - 1 >= 0)
                            f[i][s[i - 1] - 'a'][a][b] += (f[i][s[i - 1] - 'a'][a][b] + f[i - 1][c2][a][b - 1]) % MOD;
                    }
                }
            }
        }
    }

    for (int c = 0; c <= 300; c++)
    {
        for (int a = 0; a <= 300; a++)
        {
            for (int b = 0; b <= c - a; b++)
            {
                
            }
        }
    }
}

int main()
{
    int n, T;
    cin >> n >> T;
    cin >> s;

    init();
    while (T--)
    {
        int x, y, z;
        cin >> x >> y >> z;
    }
}