#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> tree[350505];
vector<int> ans;

void DFS(int now) {
    ans.push_back(now);
    for (int next: tree[now]) DFS(next);
    return;
}

void solve() {
    cin >> N;
    
    int cnt = N / 2;
    for (int i = 0; i < cnt; i++) tree[1].push_back(2 + i);
    int now = 2, now2 = 2 + cnt - 1;
    while (now <= N) {
        for (int i = 0; i < cnt; i++) tree[now].push_back(++now2);
        now += cnt;
    }
    
    for (int i = 1; i <= N; i++) {
        sort(tree[i].begin(), tree[i].end());
        while (tree[i].size()) {
            if (tree[i].back() <= N) break;
            else tree[i].pop_back();
        }
    }
    
    DFS(1);
    
    ll tot = 0;
    for (int i = 1; i <= N; i++) {
        tot += abs(i - ans[i - 1]);
    }
    
    cout << tot << '\n';
    for (int i = 1; i <= N; i++) {
        for (int a: tree[i]) cout << i << " " << a << '\n';
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