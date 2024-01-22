#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[1000005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    int ptr = 2;
    for (int i = 1; i <= N; i++) {
        while (ptr <= N) {
            if (arr[ptr] != arr[i]) break;
            ptr++;
        }
        if (ptr == N + 1) cout << -1 << " ";
        else cout << ptr << " ";
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