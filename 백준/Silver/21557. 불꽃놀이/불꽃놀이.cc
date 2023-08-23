#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[200005];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int a = arr[0], b = arr[N - 1];
    if (a > b) swap(a, b);

    int diff = b - a, chance = N - 3;
    if (diff >= chance) cout << b - (N - 2);
    else {
        b -= diff;
        chance -= diff;
        b -= chance / 2;
        cout << b - 1;
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