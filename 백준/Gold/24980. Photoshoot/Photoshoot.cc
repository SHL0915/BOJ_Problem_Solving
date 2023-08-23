#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
string S;
vector<int> arr;

void solve() {
    cin >> N >> S;
    for (int i = 0; i < N; i += 2) {
        if (S[i] == S[i + 1]) continue;
        if (S[i] == 'H') arr.push_back(1);
        else arr.push_back(0);
    }

    int ans = 0;
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] != arr[i + 1]) ans++;
    }

    if (arr.back() == 0) ans++;

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