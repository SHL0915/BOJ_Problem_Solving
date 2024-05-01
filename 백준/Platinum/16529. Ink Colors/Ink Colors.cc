#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int dp[100005][3];
vector<int> tree[100005];

int DP(int node, int k) {
    int &ret = dp[node][k];
    if (ret != -1) return ret;
    ret = 0;

    if (k == 0) {
        for (int next: tree[node]) ret += max(DP(next, 0), DP(next, 1));
        return ret;
    } else if (k == 1) {
        map<int, int> m1, m2;
        priority_queue<pii> pq;
        int tot = 0;

        for (int next: tree[node]) {
            int a = DP(next, 0), b = DP(next, 1);
            m1[next] = a;
            m2[next] = b;
            pq.push({a - b, next});
            tot += max(a, b);
        }

        for (int next: tree[node]) {
            int a = DP(next, 2);
            int cnt = 0, val = a - max(m1[next], m2[next]);
            vector<pii> v;
            while (pq.size()) {
                pii t = pq.top();
                pq.pop();
                if (t.second != next) cnt++, val += m1[t.second] - max(m1[t.second], m2[t.second]);
                v.push_back(t);
                if (cnt == 2) break;
            }

            if (cnt == 2) ret = max(ret, tot + val);
            for (pii j: v) pq.push(j);
        }

        return ret;
    } else {
        priority_queue<pii> pq;
        for (int next: tree[node]) pq.push({DP(next, 0) - DP(next, 1), next});

        if (pq.size() < 2) return ret;

        ret = 1;
        for (int i = 0; i < 2; i++) {
            pii t = pq.top();
            pq.pop();
            ret += DP(t.second, 0);
        }

        while (pq.size()) {
            pii t = pq.top();
            pq.pop();
            ret += max(DP(t.second, 0), DP(t.second, 1));
        }

        return ret;
    }
}

void solve() {
    cin >> N;
    for (int i = 2; i <= N; i++) {
        int a;
        cin >> a;
        tree[a].push_back(i);
    }

    memset(dp, -1, sizeof(dp));
    cout << DP(1, 0);

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