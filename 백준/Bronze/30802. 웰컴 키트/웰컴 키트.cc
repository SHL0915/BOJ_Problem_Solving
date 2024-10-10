#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, T, P;
int a, b, c, d, e, f;

void solve() {
    cin >> N;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> T >> P;
    
    int ans_t = 0, ans_p = 0;
    
    ans_t += (a / T) + (a % T != 0);
    ans_t += (b / T) + (b % T != 0);
    ans_t += (c / T) + (c % T != 0);
    ans_t += (d / T) + (d % T != 0);
    ans_t += (e / T) + (e % T != 0);
    ans_t += (f / T) + (f % T != 0);
    
    ans_p = (N / P);
    
    cout << ans_t << '\n' << ans_p << " " << N - ans_p * P;
    
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