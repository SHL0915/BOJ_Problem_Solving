#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N, Q;
ll arr[100005], ans[100005], cnt[100005];
pair<pii, ll> query[100005];
priority_queue<pii, vector<pii>, greater<>> pq;

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i], cnt[i] = arr[i];
        pq.push({arr[i], i});
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll d, x;
        cin >> d >> x;
        query[i] = {{d, x}, i};
    }
    
    sort(query, query + Q);
    
    ll now = 0, id;
    for (int i = 0; i < Q; i++) {
        ll d = query[i].first.first, x = query[i].first.second, idx = query[i].second;
        if (N == 3) ans[idx] = d;
        else {
            while (now < 50 * N && now < d) {
                pii a, b, c;
                a = pq.top();
                pq.pop();
                b = pq.top();
                pq.pop();
                c = pq.top();
                pq.pop();
                arr[a.second]++;
                arr[b.second]++;
                arr[c.second]++;
                pq.push({arr[a.second], a.second});
                pq.push({arr[b.second], b.second});
                pq.push({arr[c.second], c.second});
                now++;
            }
            id = pq.top().second - 1;
            if (!id) id += N;
            
            if (d > 50 * N) {
                d -= 50 * N;
                d *= 3;
                ans[idx] = arr[x] - cnt[x] + d / N;
                ll dist = (x + N - id - 1) % N;
                if (d % N > dist) ans[idx]++;
            } else ans[idx] = arr[x] - cnt[x];
        }
    }
    
    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
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