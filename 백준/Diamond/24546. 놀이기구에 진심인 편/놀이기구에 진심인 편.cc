#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 100000;
const int sqrtN = 316;

int N, K, H, W, D;
vector<pii> add[200005], del[200005];
ll cnt[200005], ccnt[355], offset[355], bucket[355][200005];

void update(int l, int r, int k) {
    while ((l % sqrtN) && l <= r) {
        int b = l / sqrtN;
        if (k == -1 && cnt[l] + offset[b] == K) ccnt[b]--;
        bucket[b][cnt[l] + sz]--;
        cnt[l] += k;
        bucket[b][cnt[l] + sz]++;
        if (k == 1 && cnt[l] + offset[b] == K) ccnt[b]++;
        l++;
    }

    while (((r + 1) % sqrtN) && l <= r) {
        int b = r / sqrtN;
        if (k == -1 && cnt[r] + offset[b] == K) ccnt[b]--;
        bucket[b][cnt[r] + sz]--;
        cnt[r] += k;
        bucket[b][cnt[r] + sz]++;
        if (k == 1 && cnt[r] + offset[b] == K) ccnt[b]++;
        r--;
    }

    while (l <= r) {
        int b = l / sqrtN;
        if (k == -1) ccnt[b] -= bucket[b][K - offset[b] + sz];
        offset[b] += k;
        if (k == 1) ccnt[b] += bucket[b][K - offset[b] + sz];
        l += sqrtN;
    }
}

ll query(int l, int r) {
    ll ret = 0;
    while ((l % sqrtN) && l <= r) {
        int b = l / sqrtN;
        if (cnt[l++] + offset[b] >= K) ret++;
    }

    while (((r + 1) % sqrtN) && l <= r) {
        int b = r / sqrtN;
        if (cnt[r--] + offset[b] >= K) ret++;
    }

    while (l <= r) {
        int b = l / sqrtN;
        ret += ccnt[b];
        l += sqrtN;
    }

    return ret;
}

void solve() {
    cin >> N >> K >> H >> W >> D;

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add[a].push_back({c, d});
        del[b].push_back({c, d});
    }

    for (int i = 1; i <= sz; i++) bucket[i / sqrtN][sz]++;

    ll ans = 0;

    for (int i = 1; i <= sz; i++) {
        for (auto &[l, r]: add[i]) update(l, r, 1);
        if (i >= max(1, H - D) && i <= min(sz, H + D)) ans += query(max(1, W - D), min(sz, W + D));
        for (auto &[l, r]: del[i]) update(l, r, -1);
    }

    cout << ans << '\n';
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