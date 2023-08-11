#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
ll ans;
ll arr[100005];
vector<int> tree[100005];
ll cnt[100005], cnt2[100005];
vector<int> factor[100005];

void DFS(int node) {
    ans += cnt2[arr[node]];

    if (factor[arr[node]].size() == 0) {
        for (ll i = 1; i * i <= arr[node]; i++) {
            if (arr[node] % i) continue;
            if (i * i == arr[node]) factor[arr[node]].push_back(i);
            else {
                factor[arr[node]].push_back(i);
                factor[arr[node]].push_back(arr[node] / i);
            }
        }
    }

    for (int i = 0; i < factor[arr[node]].size(); i++) {
        ans += cnt[factor[arr[node]][i]];
        cnt2[factor[arr[node]][i]]++;
    }

    ans -= cnt[arr[node]];
    cnt[arr[node]]++;

    for (int next: tree[node]) DFS(next);

    cnt[arr[node]]--;
    for (int i = 0; i < factor[arr[node]].size(); i++) cnt2[factor[arr[node]][i]]--;

    return;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 2; i <= N; i++) {
        int a;
        cin >> a;
        tree[a].push_back(i);
    }

    DFS(1);

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