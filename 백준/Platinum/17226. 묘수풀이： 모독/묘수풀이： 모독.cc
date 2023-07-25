#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
pair<pii, int> A[10];
pii B[10];
int BT[10];

void simulate() {
    pair<pii, int> a[10];
    pii b[10];
    for (int i = 1; i <= N; i++) a[i] = A[i];
    for (int i = 1; i <= M; i++) b[i] = B[i];

    vector<string> ans;

    for (int i = 1; i <= N; i++) {
        if (BT[i] == 0) continue;
        if (a[i].first.second <= 0 || b[BT[i]].second <= 0) return;
        string s = "attack ";
        s += ('0' + a[i].second);
        s += " ";
        s += ('0' + BT[i]);
        ans.push_back(s);
        a[i].first.second -= b[BT[i]].first;
        b[BT[i]].second -= a[i].first.first;
    }

    ans.push_back({"use modok"});

    int m = 0;
    for (int i = 1; i <= 12; i++) {
        int flag = 0;
        for (int j = 1; j <= N; j++) if (a[j].first.second == i) flag = 1;
        for (int j = 1; j <= M; j++) if (b[j].second == i) flag = 1;
        if (flag) m = i;
        else break;
    }

    for (int i = 1; i <= M; i++) b[i].second -= m + 1;

    int flag = 0;
    for (int i = 1; i <= M; i++) {
        if (b[i].second > 0) flag = 1;
    }

    if (flag) return;
    else {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
        exit(0);
    }
    return;
}

void BackTracking(int idx) {
    if (idx == N + 1) {
        simulate();
        return;
    } else {
        for (int i = 0; i <= M; i++) {
            BT[idx] = i;
            BackTracking(idx + 1);
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i].first.first >> A[i].first.second;
        A[i].second = i;
    }
    sort(A + 1, A + N + 1);

    for (int i = 1; i <= M; i++) cin >> B[i].first >> B[i].second;

    BackTracking(1);

    cout << -1;
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