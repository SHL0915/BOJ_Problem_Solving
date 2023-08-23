#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
string arr[1005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        int rev = stoi(arr[i], 0, 16);

        int m = INF, M = -1;
        for (int j = 30; j <= 39; j++) {
            m = min(m, rev ^ j);
            M = max(M, rev ^ j);
        }

        if(m >= 60) cout << "-";
        else cout << ".";
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