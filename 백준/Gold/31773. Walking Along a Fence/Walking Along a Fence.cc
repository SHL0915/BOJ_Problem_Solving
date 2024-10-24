#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, P;
pii arr[200005];
pii val[300005];
int fence[1005][1005];
int mark[1005][1005];
pair<pii, pii> query[100005];
ll psum[300005];

ll dist(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    cin >> N >> P;

    for (int i = 0; i < P; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        query[i] = {{x1, y1},
                    {x2, y2}};
        mark[x1][y1] = 1, mark[x2][y2] = 1;
    }

    int cnt = 1;
    for (int i = 1; i < P; i++) {
        int x1 = arr[i - 1].first, y1 = arr[i - 1].second, x2 = arr[i].first, y2 = arr[i].second;
        fence[x1][y1] = cnt++;

        if (x2 > x1) {
            for (int j = x1 + 1; j < x2; j++) {
                if (mark[j][y1]) fence[j][y1] = cnt++;
            }
        }

        if (x2 < x1) {
            for (int j = x1 - 1; j > x2; j--) {
                if (mark[j][y1]) fence[j][y1] = cnt++;
            }
        }

        if (y2 > y1) {
            for (int j = y1 + 1; j < y2; j++) {
                if (mark[x1][j]) fence[x1][j] = cnt++;
            }
        }

        if (y2 < y1) {
            for (int j = y1 - 1; j > y2; j--) {
                if (mark[x1][j]) fence[x1][j] = cnt++;
            }
        }
    }

    int x1 = arr[P - 1].first, y1 = arr[P - 1].second, x2 = arr[0].first, y2 = arr[0].second;
    fence[x1][y1] = cnt++;

    if (x2 > x1) {
        for (int j = x1 + 1; j < x2; j++) {
            if (mark[j][y1]) fence[j][y1] = cnt++;
        }
    }

    if (x2 < x1) {
        for (int j = x1 - 1; j > x2; j--) {
            if (mark[j][y1]) fence[j][y1] = cnt++;
        }
    }

    if (y2 > y1) {
        for (int j = y1 + 1; j < y2; j++) {
            if (mark[x1][j]) fence[x1][j] = cnt++;
        }
    }

    if (y2 < y1) {
        for (int j = y1 - 1; j > y2; j--) {
            if (mark[x1][j]) fence[x1][j] = cnt++;
        }
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) if (fence[i][j]) val[fence[i][j]] = {i, j};
    }

    ll tot = 0;
    for (int i = 1; i < cnt - 1; i++) {
        psum[i] = dist(val[i + 1], val[i]);
        tot += psum[i];
        psum[i] += psum[i - 1];
    }
    tot += dist(val[1], val[cnt - 1]);

    for (int i = 0; i < N; i++) {
        pii s = query[i].first, e = query[i].second;
        int sidx = fence[s.first][s.second];
        int eidx = fence[e.first][e.second];
        if (sidx > eidx) swap(sidx, eidx);

        ll ans = psum[eidx - 1] - psum[sidx - 1];
        ans = min(ans, tot - ans);

        cout << ans << '\n';
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
    //cin >> t;
    while (t--) solve();
    return 0;
}