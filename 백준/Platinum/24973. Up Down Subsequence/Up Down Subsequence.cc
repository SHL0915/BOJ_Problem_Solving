#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[300005];
int seg[600005];
string S;

void update(int pos, int val) {
    for (seg[pos += N] = val; pos > 0; pos >>= 1) seg[pos >> 1] = max(seg[pos], seg[pos ^ 1]);
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret = max(ret, seg[l++]);
        if (r & 1) ret = max(ret, seg[--r]);
    }
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> S;
    vector<pii> v;

    int cnt = 1;
    for (int i = 1; i < S.length(); i++) {
        if (S[i] != S[i - 1]) {
            if (S[i - 1] == 'U') v.push_back({cnt, 0});
            else v.push_back({cnt, 1});
            cnt = 1;
        } else cnt++;
    }

    if (S[N - 1] == 'U') v.push_back({cnt, 0});
    else v.push_back({cnt, 1});

    int idx = 0, ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int sz = v[i].first, t = v[i].second;
        int nidx = N;

        if (t == 0) {
            int val = 0;
            for (int j = idx; j < N; j++) {
                int q = query(1, arr[j]);
                update(arr[j], q + 1);
                val = max(val, q + 1);

                if (val == sz + 1) {
                    nidx = j;
                    break;
                }
            }

            if (val == sz + 1) {
                ans += (val - 1);
                for (int j = idx; j <= nidx; j++) update(arr[j], 0);
                idx = nidx;
            } else {
                ans += (val - 1);
                break;
            }
        } else {
            int val = 0;
            for (int j = idx; j < N; j++) {
                int q = query(arr[j], N);
                update(arr[j], q + 1);
                val = max(val, q + 1);
                if (val == sz + 1) {
                    nidx = j;
                    break;
                }
            }

            if (val == sz + 1) {
                ans += (val - 1);
                for (int j = idx; j <= nidx; j++) update(arr[j], 0);
                idx = nidx;
            } else {
                ans += (val - 1);
                break;
            }
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
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}