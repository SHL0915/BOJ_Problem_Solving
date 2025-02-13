#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int arr[1005][1005];

void solve() {
    cin >> N >> M;
    
    vector<pii> v;
    if ((N + M) % 2) {
        for (int i = 0; i < N; i++) v.push_back({i, 0});
        for (int i = 1; i < M; i++) v.push_back({N - 1, i});
    } else {
        for (int i = 0; i < N; i++) v.push_back({i, 0});
        for (int i = 1; i < M - 1; i++) v.push_back({N - 1, i});
        v.push_back({N - 2, M - 1});
        v.push_back({N - 1, M - 1});
    }
    
    vector<pii> ans;
    for (int i = 0; i < v.size(); i += 2) {
        ans.push_back(v[i]);
        ans.push_back(v[i + 1]);
        ans.push_back(v[i]);
        ans.push_back(v[i + 1]);
    }
    
    cout << ans.size() << '\n';
    for (auto i: ans) cout << i.first << " " << i.second << '\n';
    
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