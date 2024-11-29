#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll N;
ll arr[100005];

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


void solve() {
    cin >> N;
    vector<pii> points;
    points.push_back({0, 0});
    for (int i = 1; i <= N; i++) cin >> arr[i], points.push_back({i, arr[i]});
    points.push_back({N + 1, 0});
    
    vector<pii> convex_hull = Convex_Hull(points);
    vector<int> upper_convex;
    
    int flag = 0;
    for (auto i: convex_hull) {
        if (i.first == N + 1) flag = 1;
        if (flag) upper_convex.push_back(i.first);
    }
    upper_convex.push_back(0);
    reverse(upper_convex.begin(), upper_convex.end());
    
    for (int i = 1; i <= N; i++) {
        int idx = lower_bound(upper_convex.begin(), upper_convex.end(), i) - upper_convex.begin();
        if (upper_convex[idx] == i) cout << arr[i] * 100000 << '\n';
        else {
            __int128 l = upper_convex[idx - 1], r = upper_convex[idx];
            long double v1 = arr[l], v2 = arr[r];
            
            __int128 ans = v1 * 100000 + ((v2 - v1) * (i - l) * 100000 / (r - l));
            
            cout << (ll) ans << '\n';
        }
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