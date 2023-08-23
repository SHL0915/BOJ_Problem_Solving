#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N;
vector<int> val;
pii arr[1005];
int psum[1005];

void solve() {
    cin >> N;
    val.push_back(-1);
    for (int i = 0; i < N; i++) {
        char c;
        int a;
        cin >> c >> a;
        if (c == 'G') arr[i] = {0, a};
        else arr[i] = {1, a};
        val.push_back(a);
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 0; i < N; i++) {
        int t = arr[i].first, a = arr[i].second;
        a = lower_bound(val.begin(), val.end(), a) - val.begin();

        if (t == 0) psum[a]++;
        else {
            psum[0]++;
            psum[a + 1]--;
        }
    }

    for (int i = 1; i <= N; i++) psum[i] += psum[i - 1];

    int ans = INF;
    for (int i = 0; i <= N; i++) ans = min(ans, N - psum[i]);

    cout << ans;
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