#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll L, R, U, D, flag = 0;
pair<pii, pii> cmp;
pair<pii, pii> rectangle[4];
vector<pii> ans;

ll ccw(pii a, pii b, pii c);

pii sub(pii a, pii b);

void chk(pair<pii, pii> a, pair<pii, pii> b);

void Find_intersect(pii a, pii b, pii c, pii d);

void solve() {
    cin >> L >> D >> R >> U;
    cin >> cmp.first.first >> cmp.first.second >> cmp.second.first >> cmp.second.second;

    ans.clear();
    flag = 0;

    rectangle[0] = {{L, U},
                    {R, U}};
    rectangle[1] = {{L, D},
                    {R, D}};
    rectangle[2] = {{L, U},
                    {L, D}};
    rectangle[3] = {{R, U},
                    {R, D}};

    for (int i = 0; i < 4; i++) {
        chk(cmp, rectangle[i]);
        if (flag) {
            cout << 4 << '\n';
            return;
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
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

ll ccw(pii a, pii b, pii c) {
    pii u = sub(b, a);
    pii v = sub(c, b);
    ll ret = u.first * v.second - u.second * v.first;
    if (ret) ret /= abs(ret);
    return ret;
}

pii sub(pii a, pii b) {
    return {a.first - b.first, a.second - b.second};
}

void chk(pair<pii, pii> a, pair<pii, pii> b) {
    ll A = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
    ll B = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);

    if (A == 0 && B == 0) {
        if (a.first > a.second) swap(a.first, a.second);
        if (b.first > b.second) swap(b.first, b.second);
        if (a.first <= b.second && a.second >= b.first) Find_intersect(a.first, a.second, b.first, b.second);
    } else if (A <= 0 && B <= 0) Find_intersect(a.first, a.second, b.first, b.second);
}

void Find_intersect(pii a, pii b, pii c, pii d) {
    double px = (a.first * b.second - a.second * b.first) * (c.first - d.first) -
                (a.first - b.first) * (c.first * d.second - c.second * d.first);
    double py = (a.first * b.second - a.second * b.first) * (c.second - d.second) -
                (a.second - b.second) * (c.first * d.second - c.second * d.first);
    double p = (a.first - b.first) * (c.second - d.second) - (a.second - b.second) * (c.first - d.first);

    int isINF = 0;
    if (p == 0) {
        if (b == c && a <= c) {
            ans.push_back(b);
            isINF = 1;
        } else if (a == d && c <= a) {
            ans.push_back(a);
            isINF = 1;
        }
    } else {
        double x = px / p;
        double y = py / p;
        ans.push_back({x, y});
        isINF = 1;
    }

    if (isINF == 0) flag = 1;
    return;
}