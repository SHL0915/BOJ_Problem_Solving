#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

int N, Q;
ll arr[500005], psum[500005], pmax[500005];


int chk(int idx, ll v) {
    int l = idx, r = N, ok = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (pmax[m] < v) {
            ok = m;
            l = m + 1;
        } else r = m - 1;
    }
    
    return ok;
}

void solve() {
    cin >> N >> Q;
    
    for (int i = 1; i <= N; i++) cin >> arr[i], arr[i] += (i - 1);
    for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + arr[i], pmax[i] = max(pmax[i - 1], arr[i]);
    
    ll tot = 0;
    
    while (Q--) {
        ll a, b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            tot += b;
        } else {
            ll l = arr[1], r = 1e12, ok = -1;
            
            while (l <= r) {
                ll m = (l + r) / 2;
                
                int idx = chk(1, m);
                
                if (idx == -1) {
                    ok = m;
                    l = m + 1;
                    continue;
                }
                
                ll cnt = -psum[idx] + m * idx;
                
                if (cnt <= tot) {
                    ok = m;
                    l = m + 1;
                } else r = m - 1;
            }
            
            cout << ok << '\n';
        }
    }
    
    
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
    
    return 0;
}