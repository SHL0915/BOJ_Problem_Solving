#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

int N;
vector<pii> arr;

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

vector<pii> Convex_Hull(vector<pii> &v) {
    vector<pii> ret;
    sort(v.begin(), v.end());
    sort(v.begin() + 1, v.end(), [&](pii a, pii b) {
        ll res = ccw(v[0], a, b);
        if (res) return res > 0;
        else return a < b;
    });

    ret.push_back(v[0]);
    ret.push_back(v[1]);

    for (int i = 2; i < v.size(); i++) {
        pii c = v[i];
        while (ret.size() >= 2) {
            pii b = ret.back();
            ret.pop_back();
            pii a = ret.back();
            if (ccw(a, b, c) > 0) {
                ret.push_back(b);
                break;
            }
        }
        ret.push_back(c);
    }

    return ret;
}

pair<ll, pii> Rotating_Callipers(vector<pii> &v) {
    ll ret = 0;

    int idx1 = min_element(v.begin(), v.end()) - v.begin();
    int idx2 = max_element(v.begin(), v.end()) - v.begin();

    int ans1 = -1, ans2 = -1;
    int sz = v.size();
    for (int i = 0; i < v.size(); i++) {
        pii p1 = v[idx1], p1_nxt = v[(idx1 + 1) % sz];
        pii p2 = v[idx2], p2_nxt = v[(idx2 + 1) % sz];

        ll dx = p1.first - p2.first;
        ll dy = p1.second - p2.second;
        ll sqrdist = dx * dx + dy * dy;

        if (sqrdist > ret) {
            ret = sqrdist;
            ans1 = idx1;
            ans2 = idx2;
        }

        pii v1 = sub(p1, p1_nxt);
        pii v2 = sub(p2_nxt, p2);

        ll outer_product = v1.first * v2.second - v1.second * v2.first;
        if (outer_product) outer_product /= abs(outer_product);

        if (outer_product > 0) idx1 = (idx1 + 1) % sz;
        else idx2 = (idx2 + 1) % sz;
    }

    return {ret, {ans1, ans2}};
}

void solve() {
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    vector<pii> ch = Convex_Hull(arr);

    pair<ll, pii> ans = Rotating_Callipers(ch);

    cout << ans.first;
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