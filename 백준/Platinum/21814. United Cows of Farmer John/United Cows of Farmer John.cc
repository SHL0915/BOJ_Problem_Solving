#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, ans;
int arr[200005], cnt[200005];
vector<int> pos[200005];
pii query[200005];

void push(int a) {
    if (!cnt[arr[a]]) ans++;
    cnt[arr[a]]++;
}

void pop(int a) {
    if (cnt[arr[a]] == 1) ans--;
    cnt[arr[a]]--;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    for (int i = 1; i <= N; i++) pos[i].push_back(N);
    
    for (int i = 0; i < N - 1; i++) {
        int l = i + 1;
        int r = upper_bound(pos[arr[i]].begin(), pos[arr[i]].end(), i) - pos[arr[i]].begin();
        query[i] = {l, pos[arr[i]][r] - 1};
    }
    
    int B = 0;
    while (B * B < N) B++;
    
    sort(query, query + N - 1, [&](pii a, pii b) {
        if (a.first / B == b.first / B) return a.second < b.second;
        else return a.first / B < b.first / B;
    });
    
    //for (int i = 0; i < N - 1; i++) cout << query[i].first << " " << query[i].second << endl;
    
    ll res = 0;
    int l = query[0].first, r = query[0].second;
    for (int i = l; i <= r; i++) push(i);
    res += ans;
    
    for (int i = 1; i < N - 1; i++) {
        int nl = query[i].first, nr = query[i].second;
        if (nl > nr) continue;
        while (l > nl) push(--l);
        while (l < nl) pop(l++);
        while (r > nr) pop(r--);
        while (r < nr) push(++r);
        res += ans;
    }
    
    cout << res;
    
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