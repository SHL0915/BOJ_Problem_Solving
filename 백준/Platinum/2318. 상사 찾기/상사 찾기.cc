#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SAL = 10000000;

int N, M;
map<int, int> id, sal, rev;
vector<int> tree[30005];
int sz[30005], seg[20000005], parent[30005];
pair<pii, int> arr[30005];

void update(int pos, int val) {
    for (seg[pos += SAL] = val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += SAL, r += SAL; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

int find_id(int val) {
    int l = val, r = SAL;
    int ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int q = query(val, mid);
        if (q == 0) l = mid + 1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

void tree_DP(int node) {
    sz[node]++;
    for (int next: tree[node]) {
        tree_DP(next);
        sz[node] += sz[next];
    }
    return;
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        id[a] = i;
        sal[b] = i;
        rev[i] = a;
        arr[i] = {{c, b}, a};
    }
    sort(arr + 1, arr + N + 1, greater<>());

    int boss = arr[1].second;
    update(arr[1].first.second, 1);
    for (int i = 2; i <= N; i++) {
        int b = arr[i].first.second, c = arr[i].second;
        int bo = find_id(b + 1);
        parent[id[c]] = sal[bo];
        tree[parent[id[c]]].push_back(id[c]);
        update(b, 1);
    }

    tree_DP(id[boss]);

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        if (a == boss) cout << 0 << " ";
        else cout << rev[parent[id[a]]] << " ";
        cout << sz[id[a]] - 1 << '\n';
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