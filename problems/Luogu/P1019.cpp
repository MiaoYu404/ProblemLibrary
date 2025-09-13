#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct rela{
    int id;
    unsigned long long add;
};
vector <rela> fa[25];
string words[25];
int vis[25];
ll ans = 0;
void dfs (int id, ll len) {
    ++vis[id];
    ans = max(ans, len);
    for (auto x : fa[id]) {
        if (vis[x.id] < 2) {
            dfs(x.id, len + x.add);
            --vis[x.id];
        }
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        words[i] = s;
    }

    // i is father, j is son;
    for (int i = 1; i <= n; i++) {
        string f = words[i];
        for (int j = 1; j <= n; j++) {
            //if (i == j) continue;
            string son = words[j];
            int index = f.length() - 1;
            for (; index != 0; index--) {
                while (f[index] != son[0] and index != 0) index--;

                int len = f.length() - index;
                if (index == 0 or len >= son.length()) break;

                int sonIndex = 0;
                bool yes = false;
                if (f.substr(index, len) == son.substr(0, len)) yes = true;
                /*
                for (int i = index; i < f.length(); i++, sonIndex++) {
                    if (f[i] != son[sonIndex]) {yes = false; break;}
                }
                */
                if (yes) {
                    rela tmp = {j, son.length() - len};
                    fa[i].push_back(tmp);
                    break;
                }
            }
        }
    }

    string start; cin >> start;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (words[i][0] != start[0]) continue;
        dfs(i, words[i].length());
    }

    cout << ans;
    return 0;
}