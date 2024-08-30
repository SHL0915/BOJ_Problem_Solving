#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
pii S, E;
ll arr[1000005];
ll psum[1000005];
map<pii, ll> d;

ll dist(pii a, pii b) {
    ll f = psum[a.first - 1] + a.second, s = psum[b.first - 1] + b.second;
    return abs(f - s);
}

void Dijkstra(pii start) {
    priority_queue<pair<ll, pii>> pq;

    pq.push({0, start});
    d[start] = 0;

    while (pq.size()) {
        auto t = pq.top();
        pq.pop();

        pii now = t.second;
        ll v = -t.first;

        if (now == E) break;
        if (d[now] < v) continue;

        if (now.first > 1) {
            pii next = {now.first - 1, min(now.second, arr[now.first - 1] + 1)};
            if (!d.count(next) || d[next] > v + 1) {
                d[next] = v + 1;
                pq.push({-(v + 1), next});
            }

            if (now.second == 1) {
                pii next = {now.first - 1, arr[now.first - 1] + 1};
                if (!d.count(next) || d[next] > v + 1) {
                    d[next] = v + 1;
                    pq.push({-(v + 1), next});
                }
            }
        }

        if (now.first < N) {
            pii next = {now.first + 1, min(now.second, arr[now.first + 1] + 1)};
            if (!d.count(next) || d[next] > v + 1) {
                d[next] = v + 1;
                pq.push({-(v + 1), next});
            }

            if (now.second == arr[now.first] + 1) {
                pii next = {now.first + 1, 1};
                if (!d.count(next) || d[next] > v + 1) {
                    d[next] = v + 1;
                    pq.push({-(v + 1), next});
                }
            }
        }

        if (now.second != 1) {
            pii next = {now.first, 1};
            if (!d.count(next) || d[next] > v + now.second - 1) {
                d[next] = v + now.second - 1;
                pq.push({-(v + now.second - 1), next});
            }
        }

        if (now.second != arr[now.first] + 1) {
            pii next = {now.first, arr[now.first] + 1};
            if (!d.count(next) || d[next] > v + arr[now.first] + 1 - now.second) {
                d[next] = v + arr[now.first] + 1 - now.second;
                pq.push({-(v + arr[now.first] + 1 - now.second), next});
            }
        }

        if (!d.count(E) || d[E] > v + dist(now, E)) {
            d[E] = v + dist(now, E);
            pq.push({-(v + dist(now, E)), E});
        }
    }


    return;
}

void solve() {
    cin >> N;

    cin >> S.first >> S.second >> E.first >> E.second;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i] + 1;
    }

    Dijkstra(S);

    cout << d[E];

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