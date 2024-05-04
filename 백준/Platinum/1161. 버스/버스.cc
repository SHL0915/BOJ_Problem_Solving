#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, N, C;
vector<pii> query[20005];
int cnt[20005];

void solve() {
    cin >> K >> N >> C;
    for (int i = 0; i < K; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        query[s].push_back({e, c});
    }

    int ans = 0, now = 0;
    priority_queue<pii> pq;

    for (int i = 1; i <= N; i++) {
        ans += cnt[i];
        now -= cnt[i];
        for (pii a: query[i]) {
            cnt[a.first] += a.second;
            now += a.second;
            pq.push(a);
            if (now > C) {
                while (pq.size()) {
                    if (now <= C) break;
                    pii t = pq.top();
                    pq.pop();
                    cnt[t.first] -= t.second;
                    now -= t.second;
                    if (now > C) continue;
                    else {
                        int v = C - now;
                        cnt[t.first] += v;
                        now += v;
                        pq.push({t.first, v});
                    }
                }
            }
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