#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pdd = pair<long double, long double>;
const long double pi = 3.141592653589793238462;
const long double INF = 1e25;

int N;
pair<ll, pii> arr[200005];
vector<pdd> dot[200005];

long double dist(pdd a, pdd b) {
    long double dx = a.first - b.first;
    long double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

pdd convert(pair<ll, pii> a) {
    long double x = (long double) a.first * cos(((long double) a.second.first / 1000.0) / 180.0 * pi);
    long double y = (long double) a.first * sin(((long double) a.second.first / 1000.0) / 180.0 * pi);
    return {x, y};
}

long double DNC(int l, int r, vector<pdd> &v) {
    if (l >= r) return INF;
    else if (l + 1 == r) {
        return dist(v[l], v[r]);
    } else {
        int m = (l + r) / 2;
        long double lans = DNC(l, m, v), rans = DNC(m + 1, r, v);
        long double ret = min(lans, rans);

        vector<pdd> temp;
        for (int i = m; i >= l; i--) {
            long double dx = abs(v[m].first - v[i].first);
            if (dx >= ret) break;
            temp.push_back({v[i].second, v[i].first});
        }
        for (int i = m + 1; i <= r; i++) {
            long double dx = abs(v[m].first - v[i].first);
            if (dx >= ret) break;
            temp.push_back({v[i].second, v[i].first});
        }
        sort(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++) {
            for (int j = i + 1; j < temp.size(); j++) {
                long double dy = abs(temp[i].first - temp[j].first);
                if (dy >= ret) break;
                ret = min(ret, dist(temp[i], temp[j]));
            }
        }

        return ret;
    }
}

void solve() {
    cin >> N;
    vector<int> t;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
        t.push_back(arr[i].second.second);
    }

    long double ans = 1e25;
    sort(arr, arr + N);

    for (int i = 1; i < N; i++) {
        if (arr[i - 1].second.second != arr[i].second.second)
            ans = min(ans, (long double) (abs(
                    arr[i].first - arr[i - 1].first)));
    }

    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());

    for (int i = 0; i < N; i++) {
        int idx = lower_bound(t.begin(), t.end(), arr[i].second.second) - t.begin();
        pdd pos = convert(arr[i]);
        dot[idx].push_back(pos);
    }

    for (int i = 0; i < N; i++) {
        if (dot[i].size() >= 2) {
            sort(dot[i].begin(), dot[i].end());
            ans = min(ans, DNC(0, dot[i].size() - 1, dot[i]));
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
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}