#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[16];

int cal(int a, int b) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if ((a & (1 << i)) != (b & (1 << i))) ret++;
    }

    return ret;
}

void solve() {
    cin >> N;
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        int val = 0;
        if (input[0] == 'E') val += 1;
        if (input[1] == 'N') val += 2;
        if (input[2] == 'T') val += 4;
        if (input[3] == 'P') val += 8;
        arr[val]++;
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) {
                arr[i]--;
                arr[j]--;
                arr[k]--;
                if (arr[i] < 0 || arr[j] < 0 || arr[k] < 0) {
                    arr[i]++;
                    arr[j]++;
                    arr[k]++;
                    continue;
                }
                int now = 0;
                now += cal(i, j);
                now += cal(i, k);
                now += cal(j, k);

                ans = min(ans, now);
                arr[i]++;
                arr[j]++;
                arr[k]++;
            }
        }
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
    cin >> t;
    while (t--) solve();
    return 0;
}