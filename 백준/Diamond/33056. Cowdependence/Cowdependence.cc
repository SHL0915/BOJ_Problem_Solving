#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
vector<int> pos[100005];
int ans[100005];

void solve() {
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    for (int j: v) {
        if (pos[j].size() >= sqrt(N)) {
            for (int i = 1; i <= N; i++) {
                int cnt = 1;
                int now = 0;
                while (1) {
                    int nxt = upper_bound(pos[j].begin(), pos[j].end(), pos[j][now] + i) - pos[j].begin();
                    if (nxt == pos[j].size()) break;
                    cnt++;
                    now = nxt;
                }
                if (cnt == 1) {
                    ans[i]++;
                    break;
                } else {
                    ans[i] += cnt;
                    ans[i + 1] -= cnt;
                }
            }
        } else {
            
            int prev = N + 1;
            map<int, int> mp;
            mp[0] = pos[j].size();
            for (int i = 1; i <= pos[j].size(); i++) {
                int l = 1, r = N, ok = -1;
                
                while (l <= r) {
                    int m = (l + r) / 2;
                    int cnt = 1, idx = pos[j].front();
                    for (int k = 1; k < pos[j].size(); k++) {
                        if (pos[j][k] > idx + m) {
                            cnt++;
                            idx = pos[j][k];
                        }
                    }
                    
                    if (cnt <= i) {
                        ok = m;
                        r = m - 1;
                    } else l = m + 1;
                }
                
                if (ok != -1 && !mp.count(ok)) mp[ok] = i;
            }
            mp[N + 1] = 0;
            
            int now = 0;
            for (auto k: mp) {
                ans[k.first] += k.second;
                ans[k.first] -= now;
                now = k.second;
            }
            
        }
    }
    
    for (int i = 1; i <= N; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << '\n';
    }
    
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