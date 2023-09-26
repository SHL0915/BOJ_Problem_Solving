#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[250005];
vector<int> v;
ll parent[500005], mval[500005], sum[500005], cycle[500005];

int find(int a) {
    if (parent[a] == a) return parent[a];
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    parent[a] = b;
    mval[b] = max(mval[b], mval[a]);
    sum[b] += sum[a];
    cycle[b] |= cycle[a];
    return;
}

void solve() {
    cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
        v.push_back(a);
        v.push_back(b);
        ans += (a + b);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());


    for (int i = 0; i < v.size(); i++) parent[i] = i, mval[i] = v[i], sum[i] = v[i];

    for (int i = 1; i <= N; i++) {
        arr[i].first = lower_bound(v.begin(), v.end(), arr[i].first) - v.begin();
        arr[i].second = lower_bound(v.begin(), v.end(), arr[i].second) - v.begin();
        if (find(arr[i].first) == find(arr[i].second)) cycle[find(arr[i].first)] = 1;
        else merge(arr[i].first, arr[i].second);
    }

    for (int i = 0; i < v.size(); i++) {
        if (find(i) == i) {
            if (cycle[i] == 1) ans -= sum[i];
            else ans -= sum[i] - mval[i];
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