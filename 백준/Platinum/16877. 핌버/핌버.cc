#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];
int chk[3000005];
int cnt[25];
ll fibo[55];

void solve() {
    cin >> N;
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ans ^= chk[arr[i]];
    }
    
    if (ans) cout << "koosaga";
    else cout << "cubelover";
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= 32; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
    
    for (int i = 0; i <= 3000000; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j <= 32; j++) {
            if (fibo[j] > i) break;
            cnt[chk[i - fibo[j]]]++;
        }
        for (int j = 0; j < 25; j++) {
            if (!cnt[j]) {
                chk[i] = j;
                break;
            }
        }
    }
    
    //cin >> t;
    while (t--) solve();
    return 0;
}