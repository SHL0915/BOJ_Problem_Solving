#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K;
vector<int> A[21], B[21];

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int now = K + i;
        for (int j = 0; j <= 20; j++) {
            if (now & (1 << j)) A[j].push_back(i + 1);
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= 20; j++) {
            if (i & (1 << j)) B[j].push_back(i + 1);
        }
    }

    int a = 0, b = 0;
    for (int i = 0; i <= 20; i++) if (A[i].size()) a++;
    for (int i = 0; i <= 20; i++) if (B[i].size()) b++;

    if (a <= b + 1) {
        cout << a << '\n';
        for (int i = 0; i <= 20; i++) {
            if (A[i].size()) {
                cout << A[i].size() << " " << (1 << i) << '\n';
                for (int out: A[i]) cout << out << " ";
                cout << '\n';
            }
        }
    } else {
        cout << b + 1 << '\n';
        cout << N << " " << K << '\n';
        for(int i = 1; i <= N; i++) cout << i << " ";
        cout << '\n';

        for (int i = 0; i <= 20; i++) {
            if (B[i].size()) {
                cout << B[i].size() << " " << (1 << i) << '\n';
                for (int out: B[i]) cout << out << " ";
                cout << '\n';
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