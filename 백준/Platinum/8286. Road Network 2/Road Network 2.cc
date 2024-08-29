#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[2000005];

void solve() {
    cin >> N;
    priority_queue<pii> A, B;
    vector<pii> ans;
    for (int i = 1; i <= N; i++) cin >> arr[i], B.push({arr[i], i});

    A.push(B.top());
    B.pop();

    for (int i = 0; i < N - 1; i++) {
        if (A.empty() || B.empty()) {
            cout << "BRAK";
            return;
        }
        pii a = A.top(), b = B.top();
        A.pop(), B.pop();
        ans.push_back({a.second, b.second});
        if (a.first > 1) A.push({a.first - 1, a.second});
        if (b.first > 1) A.push({b.first - 1, b.second});
    }

    if (A.size() || B.size()) {
        cout << "BRAK";
        return;
    }

    for (pii i: ans) cout << i.first << " " << i.second << '\n';

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