#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int SZ = 10000;

int N;
int arr[5005], seg[20005], max_val[5005][5005];

void update(int pos, int val) {
    for (seg[pos += SZ] = val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

void solve() {
    cin >> N;
    
    memset(seg, 0, sizeof(seg));
    memset(max_val, -1, sizeof(max_val));
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            max_val[i][j] = max(max_val[i][j - 1], arr[j]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = i + 2; j <= N; j++) {
            if (arr[j] > arr[i]) {
                int q = max_val[i + 1][j - 1];
                if (q <= arr[j]) continue;
                if (query(arr[j] + 1, q - 1) > 0) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
        update(arr[i], 1);
    }
    
    reverse(arr + 1, arr + N + 1);
    
    memset(max_val, -1, sizeof(max_val));
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            max_val[i][j] = max(max_val[i][j - 1], arr[j]);
        }
    }
    
    memset(seg, 0, sizeof(seg));
    for (int i = 1; i <= N; i++) {
        for (int j = i + 2; j <= N; j++) {
            if (arr[j] > arr[i]) {
                int q = max_val[i + 1][j - 1];
                if (q <= arr[j]) continue;
                if (query(arr[j] + 1, q - 1) > 0) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
        update(arr[i], 1);
    }
    
    cout << "No\n";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}