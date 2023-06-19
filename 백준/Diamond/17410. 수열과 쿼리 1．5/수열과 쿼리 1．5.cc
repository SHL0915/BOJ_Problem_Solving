#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 10000;

int N, M, sqrtN;
int arr[100005];
int bucket[1005][10005];

void update(int pos, int k);
int query(int l, int r, int k);

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sqrtN = 2 * sqrt(N);
    
    for (int i = 1; i <= N; i++) bucket[i / sqrtN][arr[i]]++;
    for (int i = 0; i <= N / sqrtN; i++) {
        for (int j = 1; j <= SZ; j++) bucket[i][j] += bucket[i][j - 1];
    }
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int pos, k;
            cin >> pos >> k;
            update(pos, k);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(l, r, k) << '\n';
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

void update(int pos, int k) {
    int idx = pos / sqrtN;
    int org = arr[pos];
    
    arr[pos] = k;
    if (org > k) for (int i = k; i < org; i++) bucket[idx][i]++;
    else for (int i = org; i < k; i++) bucket[idx][i]--;
    
    return;
}

int query(int l, int r, int k) {
    int ret = 0;
    while (l % sqrtN && l <= r) {
        if (arr[l] > k) ret++;
        l++;
    }
    while ((r + 1) % sqrtN && l <= r) {
        if (arr[r] > k) ret++;
        r--;
    }
    while (l <= r) {
        ret += bucket[l / sqrtN][SZ] - bucket[l / sqrtN][k];
        l += sqrtN;
    }
    
    return ret;
}