#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string A, B;

void solve() {
    cin >> N >> M;
    cin >> A >> B;
    string ans = A;

    string prev = A;
    while (ans.size() < M) {
        string add = "";
        for (int i = 0; i < N; i++) {
            add = (char) ('a' + (B.back() - prev[prev.size() - 1 - i] + 26) % 26) + add;
            B.pop_back();
            if (B.size() == 0) break;
        }
        ans = add + ans;
        prev = add;
    }

    while (ans.size() > M) ans.erase(ans.begin());

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