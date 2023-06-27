#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[2][10005];

int chk(int idx);

void solve() {
    cin >> N;
    for (int i = 0; i < 2; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '0') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    int ans = 0;

    if (N == 1) {
        int cnt = arr[0][0] + arr[1][0];
        if (cnt == 0) cout << 0;
        else cout << 1;
        return;
    }

    if (arr[0][0] == 1 && arr[1][0] == 1 && arr[0][1] == 0 && arr[1][1] == 0) {
        ans++;
        arr[0][0] ^= 1;
        arr[1][0] ^= 1;
    }
    if (arr[0][N - 1] == 1 && arr[1][N - 1] == 1 && arr[0][N - 2] == 0 && arr[1][N - 2] == 0) {
        ans++;
        arr[0][N - 1] ^= 1;
        arr[1][N - 1] ^= 1;
    }

    for (int i = 1; i < N - 1; i++) {
        if (chk(i)) {
            arr[0][i] ^= 1;
            arr[1][i] ^= 1;
            ans++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (arr[0][i] == 1) {
            if (i == 0 || arr[0][i - 1] == 0) ans++;
        }
        if (arr[1][i] == 1) {
            if (i == 0 || arr[1][i - 1] == 0) ans++;
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

int chk(int idx) {
    int l = 0, r = 0;
    if (arr[0][idx] != arr[0][idx - 1] && arr[1][idx] != arr[1][idx - 1]) l = 1;
    if (arr[0][idx] != arr[0][idx + 1] && arr[1][idx] != arr[1][idx + 1]) r = 1;
    if (l == 1 && r == 1) return 1;
    else return 0;
}