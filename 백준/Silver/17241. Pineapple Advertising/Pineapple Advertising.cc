#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, Q;
vector<int> graph[200005];
int mark[200005];
int ans[200005];

void solve() {
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while (Q--) {
        int a;
        cin >> a;
        if (mark[a]) cout << 0 << '\n';
        else {
            int cnt = (ans[a] == 0);
            mark[a] = 1;
            ans[a] = 1;
            for (int b: graph[a]) {
                if (ans[b] == 0) cnt++;
                ans[b] = 1;
            }
            cout << cnt << '\n';
        }
    }
    
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