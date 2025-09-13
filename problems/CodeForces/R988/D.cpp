#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pairint;

class cmp{
    public:
    bool operator()(const pairint &a, const pairint &b) const{
        if (a.first != b.first) return a.first > b.first;
        else return a.second < b.second;
    }
};

int main() {
    int t; cin >> t; while(t--) {
        int n, m, L; cin >> n >> m >> L;
        priority_queue< pairint, vector<pairint>, cmp > h, p;      //hurdles and powers
        
        for (int i = 1; i <= n; i++) {
            int l, r; cin >> l >> r;
            h.push(make_pair(l, r));
        }

        for (int i = 1; i <= m; i++) {
            int x, v; cin >> x >> v;
            p.push(make_pair(x, v));
        }

        int k = 1;
        int cnt = 0;
        bool flag = false;
        priority_queue< int > pwr;
        while (!h.empty()) {
            auto x = h.top(); h.pop();
            auto power = p.top();
            while (power.first < x.first) {
                if(p.empty()) break;
                pwr.push(power.second); p.pop();
                power = p.top();
            } 
            while (k < x.second - x.first + 2) {
                if (pwr.empty()) {
                    printf("-1\n"); flag = true; break;
                }
                int tmp = pwr.top(); pwr.pop();
                k += tmp;
                cnt++;
            }
            if(flag) break;
        }
        if(!flag) printf("%d\n", cnt);
    }
    return 0;
}