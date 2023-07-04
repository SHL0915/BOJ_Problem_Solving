#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, tot, sub;
int arr[55];
vector<int> v;
int mark[55];

void BackTracking(int idx, int cur, int k);

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        tot += arr[i];
    }
    sort(arr, arr + N, greater<>());

    for (int i = arr[0]; i <= tot; i++) {
        if (tot % i) continue;
        v.push_back(i);
    }

    for (int i = 0; i < v.size(); i++) {
        memset(mark, -1, sizeof(mark));

        int id = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j] == v[i]) {
                mark[j] = id;
                id++;
            } else break;
        }

        for (int j = 0; j < N; j++) {
            if (mark[j] != -1) continue;
            for (int k = j + 1; k < N; k++) {
                if (mark[j] != -1) break;
                if (mark[k] != -1) continue;
                if (arr[j] + arr[k] == v[i]) {
                    mark[j] = id;
                    mark[k] = id;
                    id++;
                }
            }
        }

        sub = v[i];
        BackTracking(0, 0, id);
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

void BackTracking(int idx, int cur, int k) {
    if (k == tot / sub) {
        cout << sub << '\n';
        vector<int> ans[55];

        for (int i = 0; i < N; i++) {
            ans[mark[i]].push_back(arr[i]);
        }

        for (int i = 0; i < k; i++) {
            for (int a: ans[i]) cout << a << " ";
            cout << '\n';
        }
        exit(0);
    }

    for (int i = idx; i < N; i++) {
        if (arr[i] > sub - cur) continue;
        if (mark[i] != -1) continue;
        if (arr[i] != 0 && arr[i] == arr[i - 1] && mark[i - 1] == -1) continue;
        mark[i] = k;
        if (cur + arr[i] == sub) BackTracking(0, 0, k + 1);
        else BackTracking(idx + 1, cur + arr[i], k);
        mark[i] = -1;
    }
}