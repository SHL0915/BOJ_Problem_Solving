#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int sz = 100001;
const int sqrtN = 316;

int N, K, H, W, D;
ll now;
vector<pii> add[200005], del[200005];
ll cnt[200005], ccnt[355], bucket[355][200005];

void update(int l, int r, int k) {
    l = max(l, W - D), r = min(r, W + D);

    while ((l % sqrtN) && l <= r) {
        int b = l / sqrtN;
        bucket[b][cnt[l] + sz]--;
        cnt[l] += k;
        bucket[b][cnt[l] + sz]++;
        if (k == 1 && cnt[l] + ccnt[b] == K) now++;
        if (k == -1 && cnt[l] + ccnt[b] == K - 1) now--;
        l++;
    }

    while (((r + 1) % sqrtN) && l <= r) {
        int b = r / sqrtN;
        bucket[b][cnt[r] + sz]--;
        cnt[r] += k;
        bucket[b][cnt[r] + sz]++;
        if (k == 1 && cnt[r] + ccnt[b] == K) now++;
        if (k == -1 && cnt[r] + ccnt[b] == K - 1) now--;
        r--;
    }

    while (l <= r) {
        int b = l / sqrtN;
        ccnt[b] += k;
        if (k == 1) now += bucket[b][K - ccnt[b] + sz];
        if (k == -1) now -= bucket[b][K - 1 - ccnt[b] + sz];
        l += sqrtN;
    }
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
        if (i >= max(1, H - D) && i <= min(sz, H + D)) ans += now;
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