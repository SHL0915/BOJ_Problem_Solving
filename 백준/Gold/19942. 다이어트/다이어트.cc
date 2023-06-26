#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

struct node {
    int pi, fi, si, vi, ci;
};

int N;
int mp, mf, ms, mv;
node arr[20];
vector <vector <int>> ans;

void solve() {
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < N; i++) cin >> arr[i].pi >> arr[i].fi >> arr[i].si >> arr[i].vi >> arr[i].ci;
    int val = INF;
    for(int i = 0; i < (1 << N); i++) {
        int psum = 0, fsum = 0, ssum = 0, vsum = 0, cost = 0;
        vector <int> v;
        
        int idx = 0;
        int now = i;
        while(now) {
            if(now & 1) {
                psum += arr[idx].pi;
                fsum += arr[idx].fi;
                ssum += arr[idx].si;
                vsum += arr[idx].vi;
                cost += arr[idx].ci;
                v.push_back(idx + 1);
            }
            now /= 2;
            idx++;
        }
        
        if(psum >= mp && fsum >= mf && ssum >= ms && vsum >= mv) {
            if(cost < val) {
                val = cost;
                ans.clear();
                ans.push_back(v);
            }
            else if(cost == val) ans.push_back(v);
        }
    }
    
    if(val == INF) {
        cout << -1;
        return;
    }
    
    cout << val << '\n';
    
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans[0].size(); i++) cout << ans[0][i] << " ";
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}