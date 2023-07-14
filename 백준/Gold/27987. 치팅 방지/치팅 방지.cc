#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
pii arr[100005];
vector<int> ans[100005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[i] = {a, i + 1};
    }
    sort(arr, arr + N, greater<>());

    int SZ = arr[0].first, pos = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i].first == SZ) {
            for (int j = 0; j < SZ; j++) ans[j].push_back(arr[i].second);
        } else {
            for (int j = 0; j < arr[i].first; j++) {
                ans[pos++].push_back(arr[i].second);
                pos %= (SZ - 1);
            }
        }
    }

    for (int i = 0; i < SZ; i++) {
        for (int a: ans[i]) cout << a << " ";
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