#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int psum3[80005], psum7[80005], psum21[80005];

void solve() {
    cin >> N;
    cout << psum3[N] + psum7[N] - psum21[N] << '\n';
    return;
}

int main(void) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 80000; i++) {
        psum3[i] += psum3[i - 1];
        psum7[i] += psum7[i - 1];
        psum21[i] += psum21[i - 1];
        if (i % 3 == 0) psum3[i] += i;
        if (i % 7 == 0) psum7[i] += i;
        if (i % 21 == 0) psum21[i] += i;
    }
        
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}