#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
vector<int> graph[1000005];
int vst[1000005];
vector<pii> v;
pii cnt;

void DFS(int node, int t) {
    if (vst[node] != -1) {
        if (vst[node] != t) {
            cout << "impossible";
            exit(0);
        } else return;
    }
    vst[node] = t;
    if (t) cnt.second++;
    else cnt.first++;
    
    for (int next: graph[node]) DFS(next, t ^ 1);
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        vector<int> arr;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        for (int j = 1; j < k; j++) {
            int a = arr[j], b = arr[j - 1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    
    memset(vst, -1, sizeof(vst));
    for (int i = 1; i <= N; i++) {
        if (vst[i] == -1) {
            cnt = {0, 0};
            DFS(i, 0);
            v.push_back(cnt);
        }
    }
    
    bitset<1000005> bs;
    bs[0] = 1;
    for (pii a: v) {
        bs |= (bs << a.first) | (bs << a.second);
    }
    
    int ans = N;
    for (int i = 0; i <= N; i++) {
        if (bs[i]) ans = min(ans, abs(2 * i - N));
    }
    
    cout << ans;
    
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