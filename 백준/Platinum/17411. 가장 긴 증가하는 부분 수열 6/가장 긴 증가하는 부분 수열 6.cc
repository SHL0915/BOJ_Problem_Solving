#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

struct node {
    ll max = 0, cnt = 0;
};

int N;
pii arr[1000005];
node seg[4000005];
node temp[1000005];

node merge(node a, node b) {
    if (a.max == b.max) return {a.max, (a.cnt + b.cnt) % mod};
    else if (a.max > b.max) return a;
    else return b;
}

void update(int n, int s, int e, int pos, node val) {
    if (pos > e || pos < s) return;
    if (s == e) {
        seg[n] = val;
        return;
    }
    int mid = (s + e) / 2;
    update(n * 2, s, mid, pos, val);
    update(n * 2 + 1, mid + 1, e, pos, val);
    seg[n] = merge(seg[n * 2], seg[n * 2 + 1]);
    return;
}

node query(int n, int s, int e, int l, int r) {
    if (l > e || r < s) return {0, 0};
    if (l <= s && e <= r) return seg[n];
    int mid = (s + e) / 2;
    return merge(query(n * 2, s, mid, l, r), query(n * 2 + 1, mid + 1, e, l, r));
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    
    sort(arr + 1, arr + N + 1);
    
    int pre = 0;
    for (int i = 2; i <= N; i++) {
        if (arr[i].first == arr[i - 1].first) continue;
        for (int j = pre + 1; j < i; j++) {
            node res = query(1, 1, N, 1, arr[j].second - 1);
            if (res.max == 0) temp[j] = {1, 1};
            else temp[j] = {res.max + 1, res.cnt};
        }
        for (int j = pre + 1; j < i; j++) update(1, 1, N, arr[j].second, temp[j]);
        pre = i - 1;
    }
    
    for (int j = pre + 1; j <= N; j++) {
        node res = query(1, 1, N, 1, arr[j].second - 1);
        if (res.max == 0) temp[j] = {1, 1};
        else temp[j] = {res.max + 1, res.cnt};
    }
    for (int j = pre + 1; j <= N; j++) update(1, 1, N, arr[j].second, temp[j]);
    
    node ans = query(1, 1, N, 1, N);
    
    cout << ans.max << " " << ans.cnt;
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