#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, arr[100005], sieve[1000005];
vector<int> tree[100005], node[1000005], prime;
int vst[100005];

int DFS(int now, int par, int v) {
    int ret = 1;
    vst[now] = v;
    for (int next: tree[now]) {
        if (next == par) continue;
        if (arr[next] % v) continue;
        ret += DFS(next, now, v);
    }
    return ret;
}

void solve() {
    for (ll i = 2; i <= 1000000; i++) {
        if (!sieve[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= 1000000; j += i) sieve[j] = 1;
        }
    }

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        ll now = arr[i];
        for (ll p: prime) {
            if (p * p > now) break;
            if (now % p) continue;
            node[p].push_back(i);
            while (!(now % p)) now /= p;
        }
        if (now != 1) node[now].push_back(i);
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int ans = 0;
    for (int i: prime) {
        for (int now: node[i]) {
            if (vst[now] != i) ans = max(ans, DFS(now, now, i));
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