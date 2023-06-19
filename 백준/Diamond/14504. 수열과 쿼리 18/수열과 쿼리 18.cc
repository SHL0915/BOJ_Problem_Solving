#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, sqrtN;
int arr[100005];
vector<int> bucket[1005];

int query(int l, int r, int k);
void update(int pos, int k);

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sqrtN = sqrt(N);

    for (int i = 1; i <= N; i++) bucket[i / sqrtN].push_back(arr[i]);
    for (int i = 0; i <= (N / sqrtN); i++) sort(bucket[i].begin(), bucket[i].end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(l, r, k) << '\n';
        } else {
            int pos, k;
            cin >> pos >> k;
            update(pos, k);
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

int query(int l, int r, int k) {
    int ret = 0;
    while (l % sqrtN != 0 && l <= r) {
        if (arr[l] > k) ret++;
        l++;
    }

    while ((r + 1) % sqrtN != 0 && l <= r) {
        if (arr[r] > k) ret++;
        r--;
    }

    while (l <= r) {
        int idx = upper_bound(bucket[l / sqrtN].begin(), bucket[l / sqrtN].end(), k) - bucket[l / sqrtN].begin();
        ret += bucket[l / sqrtN].size() - idx;
        l += sqrtN;
    }

    return ret;
}

void update(int pos, int k) {
    int bidx = pos / sqrtN;
    int idx = lower_bound(bucket[bidx].begin(), bucket[bidx].end(), arr[pos]) - bucket[bidx].begin();
    bucket[bidx][idx] = k;
    sort(bucket[bidx].begin(), bucket[bidx].end());
    arr[pos] = k;

    return;
}