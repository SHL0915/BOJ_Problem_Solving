#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, W;
int arr[5005];
int A[800008];

void solve() {
    cin >> W >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    for (int i = 0; i < N; i++) {
        int now = arr[i];
        for (int j = i + 1; j < N; j++) {
            int a = arr[j];
            if (now + a > W) continue;
            if (A[W - (now + a)]) {
                cout << "YES";
                return;
            }
        }
        
        for (int j = 0; j < i - 1; j++) A[now + arr[j]] = 1;
    }
    
    cout << "NO";
    
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