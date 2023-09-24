#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int N, M, ans = INF;
vector<pii> graph[100005];
pii arr[100005];
int vst[100005];

void DFS(int node) {
    for (pii next: graph[node]) {
        int nxt = next.first, val = next.second;
        pii nval = {-arr[node].first, -(val + arr[node].second)};
        if (vst[nxt]) {
            if (arr[nxt] == nval) continue;
            else {
                if (arr[nxt].first == nval.first) {
                    cout << "No";
                    exit(0);
                } else {
                    int nans = nval.second - arr[nxt].second;
                    if (nval.first == -1) nans *= -1;
                    if (nans % 2) {
                        cout << "No";
                        exit(0);
                    }
                    if (ans == INF) ans = nans / 2;
                    else {
                        if (ans == nans / 2) continue;
                        else {
                            cout << "No";
                            exit(0);
                        }
                    }
                }
            }
        } else {
            vst[nxt] = 1;
            arr[nxt] = nval;
            DFS(nxt);
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vst[1] = 1;
    arr[1] = {1, 0};
    DFS(1);

    cout << "Yes\n";
    if (ans != INF) {
        for (int i = 1; i <= N; i++) cout << ans * arr[i].first - arr[i].second << " ";
    } else {
        vector<int> v;
        for (int i = 1; i <= N; i++) v.push_back(arr[i].second * arr[i].first);
        sort(v.begin(), v.end());

        ans = v[N / 2];
        for (int i = 1; i <= N; i++) cout << ans * arr[i].first - arr[i].second << " ";
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