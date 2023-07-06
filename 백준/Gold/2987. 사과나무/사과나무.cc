#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii triangle[3];

pii sub(pii a, pii b) {
    return {a.first - b.first, a.second - b.second};
}

ll ccw(pii a, pii b, pii c) {
    pii u = sub(b, a);
    pii v = sub(c, b);
    ll ret = u.first * v.second - u.second * v.first;
    if (ret) ret /= abs(ret);
    return ret;
}

void solve() {
    for (int i = 0; i < 3; i++) cin >> triangle[i].first >> triangle[i].second;

    sort(triangle, triangle + 3);
    sort(triangle + 1, triangle + 3, [&](pii a, pii b) {
        ll res = ccw(a, b, triangle[0]);
        if (res) return res > 0;
        else return a < b;
    });

    ll area = 0;
    for (int i = 0; i < 3; i++) {
        pii now = triangle[i], next = triangle[(i + 1) % 3];
        area += (now.first * next.second - now.second * next.first);
    }

    area = abs(area);
    cout << (double) (area) / 2 << '\n';

    int cnt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        pii in;
        cin >> in.first >> in.second;

        vector<int> v;
        for (int j = 0; j < 3; j++) {
            pii now = triangle[j], next = triangle[(j + 1) % 3];
            v.push_back(ccw(now, next, in));
        }

        int val = v[0];
        int flag = 0;
        for (int j = 1; j <= 2; j++) {
            if (val * v[j] < 0) flag = 1;
        }

        if (flag == 0) cnt++;
    }

    cout << cnt;
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}