#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[100005];
int B[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    
    int flag = 0;
    for (int i = 0; i < N; i++) if (A[i] != B[i]) flag = 1;
    
    if (flag == 0) {
        cout << "POSSIBLE";
        return;
    }
    
    for (int i = 1; i < N - 1; i++) {
        int mid = B[i];
        if (B[i - 1] > mid && B[i + 1] < mid) {
            cout << "POSSIBLE";
            return;
        }
        if (B[i - 1] < mid && B[i + 1] > mid) {
            cout << "POSSIBLE";
            return;
        }
    }
    
    cout << "IMPOSSIBLE";
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