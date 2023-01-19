#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;

ll N, M, a, b, c;
ll arr[200001];
vector <ll> min_tree, sum_tree;

void update_sum(int node, int start, int end, int idx, ll val);
void update_min(int node, int start, int end, int idx, ll val);
ll query_sum(int node, int start, int end, int left, int right);
ll query_min(int node, int start, int end, int left, int right);
int search_left(int left, int right, int val);
int search_right(int left, int right, int val);

void solve() {
    cin >> N;
    min_tree.resize(4 * N, INF);
    sum_tree.resize(4 * N, 0);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update_sum(1, 1, N, i, arr[i]);
        update_min(1, 1, N, i, arr[i]);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update_sum(1, 1, N, b, c);
            update_min(1, 1, N, b, c);
        }
        else {
            int l = search_left(1, b, c), r = search_right(b, N, c);
            if (query_min(1, 1, N, l, l) < c) l++;
            if (query_min(1, 1, N, r, r) < c) r--;
            cout << query_sum(1, 1, N, l, r) << '\n';
        }
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

void update_sum(int node, int start, int end, int idx, ll val) {
    if (idx > end || idx < start) return;
    if (start == end) {
        sum_tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update_sum(node * 2, start, mid, idx, val);
    update_sum(node * 2 + 1, mid + 1, end, idx, val);
    sum_tree[node] = sum_tree[node * 2] + sum_tree[node * 2 + 1];
    return;
}

void update_min(int node, int start, int end, int idx, ll val) {
    if (idx > end || idx < start) return;
    if (start == end) {
        min_tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update_min(node * 2, start, mid, idx, val);
    update_min(node * 2 + 1, mid + 1, end, idx, val);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    return;
}

ll query_sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return sum_tree[node];
    int mid = (start + end) / 2;
    return (query_sum(node * 2, start, mid, left, right) + query_sum(node * 2 + 1, mid + 1, end, left, right));
}

ll query_min(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return INF;
    if (left <= start && end <= right) return min_tree[node];
    int mid = (start + end) / 2;
    return min(query_min(node * 2, start, mid, left, right), query_min(node * 2 + 1, mid + 1, end, left, right));
}

int search_left(int left, int right, int val) {
    if (left < right) {
        int mid = (left + right) / 2;
        ll q = query_min(1, 1, N, mid, b);
        if (q < val) return search_left(mid + 1, right, val);
        else return search_left(left, mid - 1, val);
    }
    else return left;
}

int search_right(int left, int right, int val) {
    if (left < right) {
        int mid = (left + right) / 2;
        ll q = query_min(1, 1, N, b, mid);
        if (q < val) return search_right(left, mid - 1, val);
        else return search_right(mid + 1, right, val);
    }
    else return left;
}