#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const double INF = 1000000000000000000;

ll N, K, X;
ll arr[1505];
double ans[5];

void solve() {
    cin >> N >> K >> X;
    ll tot = 0;
    double aans = INF;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        tot += arr[i];
    }
    sort(arr, arr + N);
    
    aans = abs((double) tot / N - X);
    
    for (int i = 1; i <= K; i++) ans[i] = INF;
    
    ll want = tot - X * (N - 1);
    for (int i = 0; i < N; i++) ans[1] = min(ans[1], (double) abs(want - arr[i]));
    ans[1] = ans[1] / (N - 1);
    
    if (N > 2) {
        want = tot - X * (N - 2);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                ans[2] = min(ans[2], (double) abs(want - arr[i] - arr[j]));
            }
        }
        ans[2] = ans[2] / (N - 2);
    }
    
    if (N > 3) {
        want = tot - X * (N - 3);
        for (int i = 0; i < N; i++) {
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                ll sum = arr[i] + arr[l] + arr[r];
                ans[3] = min(ans[3], (double) abs(want - sum));
                if (sum > want) r--;
                else l++;
            }
        }
        ans[3] = ans[3] / (N - 3);
    }
    
    if (N > 4) {
        want = tot - X * (N - 4);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int l = j + 1;
                int r = N - 1;
                while (l < r) {
                    ll sum = arr[i] + arr[j] + arr[l] + arr[r];
                    ans[4] = min(ans[4], (double) abs(want - sum));
                    if (sum > want) r--;
                    else l++;
                }
            }
        }
        ans[4] = ans[4] / (N - 4);
    }
    
    for (int i = 1; i <= K; i++) aans = min(aans, ans[i]);
    
    cout << aans;
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(9);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}