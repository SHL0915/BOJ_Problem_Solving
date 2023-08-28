#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int M, N, K;
int arr[100005];
int seg[200005];

void update(int pos, int val) {
    for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = min(seg[pos], seg[pos ^ 1]);
    return;
}

int query(int l, int r) {
    r++;
    int ret = INF;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = min(ret, seg[l++]);
        if (r & 1) ret = min(ret, seg[--r]);
    }
    return ret;
}

void solve() {
    cin >> M >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    set<pii> val, idx;

    int now, ridx = 1;
    while (ridx <= N) {
        while (val.size() < K && ridx <= N) {
            val.insert({arr[ridx], ridx});
            idx.insert({ridx, arr[ridx]});
            ridx++;
        }

        int fidx = (*idx.begin()).first;
        now = query(1, N);

        while (val.size()) {
            pii f = *val.begin();
            if (f.first < now + K) {
                val.erase(f);
                idx.erase({f.second, f.first});
                arr[f.second] = INF;
                update(f.second, INF);
            } else break;
        }

        if (val.size() == K) {
            pii f = *idx.begin();
            val.erase({f.second, f.first});
            idx.erase(f);
        }
    }

    int lidx = -1;
    if (idx.size()) lidx = (*idx.begin()).first;
    else {
        for (int i = N; i >= 1; i--) {
            if (arr[i] != INF) {
                lidx = i;
                break;
            }
        }

        if (lidx == -1) {
            cout << "YES\n";
            return;
        }
    }

    while (lidx >= 1) {
        while (val.size() < K && lidx >= 1) {
            if (arr[lidx] == INF) {
                lidx--;
                continue;
            }
            val.insert({arr[lidx], lidx});
            idx.insert({lidx, arr[lidx]});
            lidx--;
        }

        now = query(1, N);

        while (val.size()) {
            pii f = *val.begin();
            if (f.first < now + K) {
                val.erase(f);
                idx.erase({f.second, f.first});
                arr[f.second] = INF;
                update(f.second, INF);
            } else break;
        }

        if (val.size() == K) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}