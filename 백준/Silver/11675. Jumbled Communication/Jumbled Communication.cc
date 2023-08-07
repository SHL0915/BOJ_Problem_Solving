#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[100005];

void solve() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) {
            cout << 0 << " ";
            continue;
        }
        for (int j = 0; j <= 255; j++) {
            int res = j ^ (j << 1);
            if(res >= 256) res -= 256;
            if (res == arr[i]) {
                cout << j << " ";
                break;
            }
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