#include <bits/stdc++.h>
#include <random>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll W, H, cnt;
string in, sky = "sky";
int mark[10005];

void solve() {
    cin >> W >> H;
    
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, W);
    
    ll now = 1;
    pii ans = {1, 0};
    
    int tt = 0;
    
    while (cnt < W) {
        if(ans.second == H) break;
        
        int a = dis(gen);
        if (mark[a]) continue;
        mark[a] = 1;
        cnt++;
        
        cout << "? " << a << " " << ans.second + 1 << endl;
        cin >> in;
        if (in == sky) continue;
        else {
            ll l = ans.second + 1, r = H;
            ll h = ans.second + 1;
            while (l <= r) {
                ll mid = (l + r) / 2;
                cout << "? " << a << " " << mid << endl;
                cin >> in;
                if (in == sky) r = mid - 1;
                else {
                    l = mid + 1;
                    h = mid;
                }
            }
            ans = {a, h};
        }
    }
    
    cout << "! " << ans.first << " " << ans.second << endl;
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}