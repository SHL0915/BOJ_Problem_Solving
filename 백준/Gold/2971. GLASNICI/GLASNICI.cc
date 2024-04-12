#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
double K;
double arr[100005];

void solve() {
    cin >> K;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    if (N == 1) {
        cout << 0;
        return;
    }
    
    double l = 0, r = arr[N - 1];
    int cnt = 100;
    
    while (cnt--) {
        double m = (l + r) / 2;
        double temp[100005];
        for (int i = 0; i < N; i++) temp[i] = arr[i];
        temp[0] += m;
        int flag = 0;
        for (int i = 1; i < N; i++) {
            if (temp[i] - m >= temp[i - 1] + K) {
                l = m;
                flag = 1;
                break;
            } else if (temp[i] + m >= temp[i - 1] + K) temp[i] = temp[i - 1] + K;
            else temp[i] = max(temp[i - 1], temp[i] + m);
        }
        
        if (flag) continue;
        else r = m;
    }
    
    cout << (l + r) / 2;
    
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(6);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}