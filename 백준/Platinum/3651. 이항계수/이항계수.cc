#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

ll M;
vector<pii> ans;
vector<ll> nCr[40005];

void find_nC1() {
    ans.push_back({M, 1});
    ans.push_back({M, M - 1});
    return;
}

void find_nC2() {
    ll l = 2, r = 1e9;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll v = m * (m - 1) / 2;
        if (v > M) r = m - 1;
        else if (v == M) {
            ans.push_back({m, 2});
            ans.push_back({m, m - 2});
            break;
        } else l = m + 1;
    }
    return;
}

void find_nC3() {
    ll l = 3, r = 1e6;
    while (l <= r) {
        ll m = (l + r) / 2;
        ll v = m * (m - 1) * (m - 2) / 6;
        if (v > M) r = m - 1;
        else if (v == M) {
            ans.push_back({m, 3});
            ans.push_back({m, m - 3});
            break;
        } else l = m + 1;
    }
    return;
}


void solve() {
    cin >> M;

    find_nC1();
    find_nC2();
    find_nC3();

    nCr[1].push_back(1);
    nCr[1].push_back(1);
    for (int i = 2; i <= 40000; i++) {
        nCr[i].push_back(1);
        for (int j = 1; j <= i; j++) {
            if (j == i) nCr[i].push_back(1);
            else {
                if (j >= nCr[i - 1].size()) break;
                else {
                    ll v = nCr[i - 1][j - 1] + nCr[i - 1][j];
                    if (v > M) break;
                    else nCr[i].push_back(v);
                }
            }
        }
    }


    for (int i = 4; i <= 40000; i++) {
        ll l = 0, r = min(i / 2, (int) nCr[i].size() - 1);
        while (l <= r) {
            ll m = (l + r) / 2;
            ll v = nCr[i][m];
            if (v > M) r = m - 1;
            else if (v == M) {
                ans.push_back({i, m});
                ans.push_back({i, i - m});
                break;
            } else l = m + 1;
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
    for (pii a: ans) cout << a.first << " " << a.second << '\n';


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