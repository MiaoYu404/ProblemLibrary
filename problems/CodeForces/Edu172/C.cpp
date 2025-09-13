#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
ll num[200010];

int main () {
    int t; cin >> t;
    for (int i = 1; i <= 200005; i++) num[i] = num[i - 1] + i;
    while (t--) {
        cin >> n >> k;
        string s; cin >> s;
        int index = 0; int cur = 0; int cnt = 0;
        while(index < n) {
            int ones = 0; while (index < n) {if(s[index] == '1') ones++; else break; index++;}
            int zeros = 0; while (index < n) {if(s[index] == '0') zeros++; else break; index++;}

            int dif = ones - zeros;
            if (ones < zeros) {cnt += dif * cur;}
            else if (dif == 0) {cur += 1; continue;}
            else {
                if((num[cur + dif - 1] - num[cur] + cur) + cnt < k) cnt += num[cur + dif - 1] - num[cur] + cur, cur += dif;
                else if ((num[cur + dif - 1] - num[cur] + cur) + cnt == k) {cur += dif, cnt = k; break;}
                else {
                    int l = 0, r = dif; int mid;
                    while (l < r){
                        mid = l + r >> 1;
                        int ans = (num[cur + mid] - num[cur] + cur) + (dif - mid - 1) * (cur + mid) + cnt;
                        //cout << ans << endl;
                        if(ans < k) l = mid + 1;
                        else if (ans == k) {r = mid, cnt = k; break;}
                        else r = mid;
                    }
                    int ans = (num[cur + r] - num[cur] + cur) + (dif - r - 1) * (cur + r) + cnt;
                    if(ans >= k) {cnt += ans - cnt; cur += r + 1; break;}
                }
            }
            cur++;
        }
        if(cnt < k) cout << -1 << endl;
        else cout << cur << endl;
    }
}