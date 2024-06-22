#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
string arr[1005];
vector<int> graph[1005];
int vst[1005], path[1005];
queue<int> q;

void BFS() {
    int now = q.front();
    q.pop();
    
    for (int i: graph[now]) {
        if (vst[i] != -1) continue;
        path[i] = now;
        vst[i] = 1;
        q.push(i);
    }
    
    return;
}

int dist(string a, string b) {
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) d++;
    }
    return d;
}

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist(arr[i], arr[j]) == 1) graph[i].push_back(j);
        }
    }
    
    memset(vst, -1, sizeof(vst));
    int a, b;
    cin >> a >> b;
    vst[a] = 0;
    q.push(a);
    
    while (q.size()) BFS();
    
    if (vst[b] == -1) {
        cout << -1;
        return;
    }
    
    vector<int> ans;
    int now = b;
    ans.push_back(now);
    while (now != a) {
        now = path[now];
        ans.push_back(now);
    }
    
    reverse(ans.begin(), ans.end());
    
    for (int i: ans) cout << i << " ";
    
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