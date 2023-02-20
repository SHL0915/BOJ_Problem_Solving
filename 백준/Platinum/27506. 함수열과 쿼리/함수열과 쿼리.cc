#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
int arr[100001][5];
vector <int> org;
vector <vector <int>> tree;

void build(int node, int start, int end);
void update(int node, int start, int end, int idx, vector <int>& val);
vector <int> query(int node, int start, int end, int left, int right);

void solve() {
    cin >> N;
    org.resize(6);
    for (int i = 1; i < 6; i++) org[i] = i;

    tree.resize(4 * N, org);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 5; j++) cin >> arr[i][j];        
    }
    build(1, 1, N);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, a, b;
        vector <int> target(6);
        cin >> u >> a >> b >> target[1] >> target[2] >> target[3] >> target[4] >> target[5];

        vector <int> r, l;
        if (u == b) r = org;
        else r = query(1, 1, N, u + 1, b);
        if (u == a) l = org;
        else l = query(1, 1, N, a, u - 1);

        int pos[6];
        int nn[6];
        int ans[6];
        for (int i = 1; i <= 5; i++) pos[l[i]] = i;
        for (int i = 1; i <= 5; i++) nn[r[i]] = target[i];
        for (int i = 1; i <= 5; i++) ans[i] = pos[nn[i]];
        
        vector <int> udt(6);
        for (int i = 0; i <= 5; i++) udt[i] = ans[i];
        update(1, 1, N, u, udt);

        for (int i = 1; i <= 5; i++) cout << ans[i] << " ";
        cout << '\n';
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

void build(int node, int start, int end) {
    if (start == end) {
        for (int i = 1; i <= 5; i++) tree[node][i] = arr[start][i];
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    vector <int>& l = tree[node * 2], & r = tree[node * 2 + 1];
    for (int i = 1; i <= 5; i++) tree[node][i] = l[r[i]];
    return;
}

void update(int node, int start, int end, int idx, vector <int>& val) {
    if (idx > end || idx < start) return;
    if (start == end) {
        for (int i = 1; i <= 5; i++) tree[node][i] = val[i];
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    vector <int>& l = tree[node * 2], & r = tree[node * 2 + 1];
    for (int i = 1; i <= 5; i++) tree[node][i] = l[r[i]];
    return;
}

vector <int> query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return org;
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    vector <int> ret;
    ret.resize(6);
    vector <int> l = query(node * 2, start, mid, left, right), r = query(node * 2 + 1, mid + 1, end, left, right);
    for (int i = 1; i <= 5; i++) ret[i] = l[r[i]];
    return ret;
}