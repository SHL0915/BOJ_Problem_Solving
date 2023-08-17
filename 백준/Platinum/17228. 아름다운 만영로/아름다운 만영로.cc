#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll mod1 = 6643838879;
const ll mod2 = 2147483647;
const ll base = 236;

ll N, ans, A, B;
pii hash_val;
string S;
int arr[500005];
vector<pii> tree[500005];

void DFS(int node, int len, pii val, deque<int> dq) {
    if (len >= S.length() && hash_val == val) ans++;

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        int nval = tree[node][i].second;
        ll val1 = val.first, val2 = val.second;

        if (len < S.length()) {
            val1 = (val1 * base + nval) % mod1;
            val2 = (val2 * base + nval) % mod2;

            dq.push_back(nval);
            DFS(next, len + 1, {val1, val2}, dq);
            dq.pop_back();
        } else {
            val1 = (val1 * base + A * dq[0] + nval) % mod1;
            val2 = (val2 * base + B * dq[0] + nval) % mod2;
            int f = dq[0];
            dq.pop_front();
            dq.push_back(nval);
            DFS(next, len + 1, {val1, val2}, dq);
            dq.push_front(f);
            dq.pop_back();
        }
    }

    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c - 'a' + 1});
    }
    cin >> S;

    for (int i = 0; i < S.length(); i++) arr[i] = S[i] - 'a' + 1;
    A = 1;
    B = 1;

    ll val1 = 0;
    ll val2 = 0;
    for (int i = 0; i < S.length(); i++) {
        val1 = (val1 * base + arr[i]) % mod1;
        val2 = (val2 * base + arr[i]) % mod2;
        A = (A * base) % mod1;
        B = (B * base) % mod2;
    }
    A = (mod1 - A);
    B = (mod2 - B);

    hash_val = {val1, val2};

    deque<int> dq;
    DFS(1, 0, {0, 0}, dq);

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