#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
pii arr[1000005];
int parent[500005], mark[500005];

int find(int a) {
    if (parent[a] == a) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b) parent[b] = a;
    else parent[a] = b;
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 1; i <= N + 1; i++) parent[i] = i;
    
    int ans = 0, remain = 0;
    for (int i = 0; i < M; i++) {
        remain++;
        int l = arr[i].first, r = arr[i].second;
        for (int j = l; j < r;) {
            if (mark[j]) j = find(j);
            else {
                if (remain) remain--;
                else ans++;
                merge(j, j + 1);
                mark[j] = 1;
            }
        }
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