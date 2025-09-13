#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool breakDown(ll x, unordered_map<ll, int> &freq) {
    if (freq[x] > 0) {freq[x]--; return true;}
    if (x == 1) {return false;}

    ll left = x / 2;
    ll right = x - left;
    if (!breakDown(left, freq)) {return false;}
    if (!breakDown(right, freq)) {return false;}

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t; while(t--) {
        ll n, m;
        cin >> n >> m;

        vector<ll> a(n), b(m);
        ll sumA = 0, sumB = 0;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a[i] = x;
            sumA += a[i];
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            b[i] = x;
            sumB += b[i];
        }

        if(sumA != sumB) {cout << "No" << endl; continue;}

        unordered_map<ll, int> freq;
        freq.reserve(n * 2);    // 限制大小
        for(auto &x : a){ freq[x]++; }

        bool possible = true;
        for(auto &x : b){
            if(!breakDown(x, freq)){
                possible = false;
                break;
            }
        }

        if(possible) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
