#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, Q;
set<int> arr[500005];

void solve() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            arr[i].insert(b);
        }
    }

    while (Q--) {
        int c;
        cin >> c;

        if (c == 2) {
            int a;
            cin >> a;
            cout << arr[a].size() << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            if (arr[a].size() < arr[b].size()) {
                for (int i: arr[a]) arr[b].insert(i);
                swap(arr[a], arr[b]);
                arr[b].clear();
            } else {
                for (int i: arr[b]) arr[a].insert(i);
                arr[b].clear();
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