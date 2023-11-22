#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, K;
int arr[105];
int cnt[8], p[8];
map<vector<int>, int> dp;

pii convert(int a) {
    pii ret;
    if (a * 2 < K) {
        ret.first = a;
        ret.second = -1;
    } else if (a * 2 == K) {
        ret.first = a;
        ret.second = 1;
    } else {
        if (a == p[1]) ret.first = 1;
        else if (a == p[2]) ret.first = 2;
        else ret.first = 3;
        ret.second = 1;
    }
    return ret;
}

int rev(pii a) {
    if (a.second == -1) return abs(a.first);
    else return p[a.first];
}

void add(vector<int> &a, int b) {
    pii c = convert(b);
    a[c.first] += c.second;
    if (K % 2 == 0) a[K / 2] %= 2;
    return;
}

void sub(vector<int> &a, int b) {
    pii c = convert(b);
    a[c.first] -= c.second;
    if (K % 2 == 0) {
        a[K / 2] += 2;
        a[K / 2] %= 2;
    }
    return;
}

int DP(vector<int> now) {
    int flag = 0;
    for (int i = 1; i <= 4; i++) if (now[i] != 0) flag = 1;
    if (flag == 0) return dp[now] = 0;
    if (dp.count(now)) return dp[now];
    int &ret = dp[now];
    ret = INF;
    
    for (int i = 1; i <= 4; i++) {
        if (now[i] == 0) continue;
        for (int j = i; j <= 4; j++) {
            if (now[j] == 0) continue;
            if (i == j && abs(now[j]) < 2) continue;
            int a = rev({i, now[i] / abs(now[i])}) + rev({j, now[j] / abs(now[j])});
            if (a > K) {
                vector<int> nxt = now;
                sub(nxt, rev({i, now[i] / abs(now[i])}));
                sub(nxt, rev({j, now[j] / abs(now[j])}));
                add(nxt, a % K);
                ret = min(ret, 1 + DP(nxt));
            } else if (a == K) {
                vector<int> nxt = now;
                sub(nxt, rev({i, now[i] / abs(now[i])}));
                sub(nxt, rev({j, now[j] / abs(now[j])}));
                ret = min(ret, DP(nxt));
            } else {
                vector<int> nxt = now;
                sub(nxt, rev({i, now[i] / abs(now[i])}));
                sub(nxt, rev({j, now[j] / abs(now[j])}));
                add(nxt, a);
                ret = min(ret, DP(nxt));
            }
        }
    }
    
    return ret;
}

void solve() {
    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ans += arr[i] / K;
        if (arr[i] % K == 0) ans--;
        cnt[arr[i] % K]++;
    }
    
    vector<int> a(5, 0);
    for (int i = 1; i <= K / 2; i++) {
        a[i] -= cnt[i];
        a[i] += cnt[K - i];
        p[i] = K - i;
        p[K - i] = i;
    }
    if (K % 2 == 0) a[K / 2] = cnt[K / 2] % 2;
    
    cout << ans + DP(a);
    
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