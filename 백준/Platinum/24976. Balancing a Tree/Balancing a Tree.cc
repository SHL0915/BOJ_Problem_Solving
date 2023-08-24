#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int B, N, ans;
int p[100005], arr[100005];
pii range[100005];
vector<int> tree[100005];

void init() {
    for (int i = 1; i <= N; i++) tree[i].clear();
    return;
}

void DFS(int node, int M, int m) {
    M = max(M, arr[node]);
    m = min(m, arr[node]);
    ans = max({ans, abs(M - arr[node]), abs(m - arr[node])});

    for (int next: tree[node]) DFS(next, M, m);

    return;
}

void solve() {
    cin >> N;
    init();
    for (int i = 2; i <= N; i++) {
        cin >> p[i];
        tree[p[i]].push_back(i);
    }

    vector<pii> v;
    for (int i = 1; i <= N; i++) {
        cin >> range[i].first >> range[i].second;
        v.emplace_back(range[i]);
    }
    sort(v.begin(), v.end());

    vector<pii> vv;
    for (int i = 0; i < v.size(); i++) {
        if (vv.size() == 0) vv.push_back(v[i]);
        else {
            if (v[i].first <= vv.back().second) {
                vv.back().first = v[i].first;
                vv.back().second = min(vv.back().second, v[i].second);
            } else vv.push_back(v[i]);
        }
    }

    int mid;
    if (vv.size() == 1) mid = vv.front().first;
    else mid = (vv.front().second + vv.back().first) / 2;

    for (int i = 1; i <= N; i++) {
        if (range[i].first > mid) arr[i] = range[i].first;
        else if (mid <= range[i].second) arr[i] = mid;
        else arr[i] = range[i].second;
    }

    ans = 0;
    DFS(1, -INF, INF);
    cout << ans << '\n';

    if (B == 1) {
        for (int i = 1; i <= N; i++) cout << arr[i] << " ";
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
    cin >> t >> B;
    while (t--) solve();
    return 0;
}