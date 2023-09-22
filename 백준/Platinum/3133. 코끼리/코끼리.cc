#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll mod = 1000000007;

struct node {
    ll max, sum;
};

int N;
pii arr[300005];
node seg[1200005];
node temp[300005];

node merge(node a, node b) {
    if (a.max == b.max) return {a.max, (a.sum + b.sum) % mod};
    else if (a.max > b.max) return a;
    else return b;
}

void update(int n, int s, int e, int pos, node v) {
    if (pos > e || pos < s) return;
    if (s == e) {
        seg[n] = merge(v, seg[n]);
        return;
    }
    int mid = (s + e) / 2;
    update(n * 2, s, mid, pos, v);
    update(n * 2 + 1, mid + 1, e, pos, v);
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
    vector<int> val;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
        val.push_back(arr[i].second);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    
    for (int i = 1; i <= N; i++) arr[i].second = lower_bound(val.begin(), val.end(), arr[i].second) - val.begin() + 1;
    sort(arr + 1, arr + N + 1);
    
    int pre = 0;
    for (int i = 2; i <= N; i++) {
        if (arr[i].first != arr[i - 1].first) {
            for (int j = pre + 1; j < i; j++) {
                node res = query(1, 1, N, 1, arr[j].second - 1);
                temp[j] = res;
            }
            
            for (int j = pre + 1; j < i; j++) {
                node now = temp[j];
                if (now.max == 0) update(1, 1, N, arr[j].second, {1, 1});
                else update(1, 1, N, arr[j].second, {now.max + 1, now.sum});
            }
            pre = i - 1;
        }
    }
    
    for (int j = pre + 1; j <= N; j++) {
        node res = query(1, 1, N, 1, arr[j].second - 1);
        temp[j] = res;
    }
    for (int j = pre + 1; j <= N; j++) {
        node now = temp[j];
        if (now.max == 0) update(1, 1, N, arr[j].second, {1, 1});
        else update(1, 1, N, arr[j].second, {now.max + 1, now.sum});
    }
    
    
    node ans = query(1, 1, N, 1, N);
    cout << ans.max << '\n' << ans.sum;
    
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