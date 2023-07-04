#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct ans {
    char player;
    string act;
    int block;
};

int N, M;
vector<ans> bucket[200005];
int mark[200005];

void solve() {
    cin >> N >> M;
    int cnt = M;

    for (int i = 0; i < M; i++) {
        char a;
        string b;
        int c;
        cin >> a >> b >> c;
        mark[c] = 1;
        bucket[i].push_back({a, b, c});
    }

    for (int i = 0; i < M - 1; i++) {
        if (bucket[i][0].player == bucket[i + 1][0].player) {
            if (bucket[i][0].player == 'A') bucket[i].push_back({'B', "CHAIN", -1});
            else bucket[i].push_back({'A', "CHAIN", -1});
            cnt++;
        }
    }

    if (bucket[M - 1][0].player == 'A') {
        bucket[M - 1].push_back({'B', "CHAIN", -1});
        cnt++;
    }

    if (mark[1] == 0) {
        cout << "NO";
        return;
    }

    if (cnt > 2 * N) {
        cout << "NO";
        return;
    }

    priority_queue<pii> pq;
    set<int> s;
    for (int i = 1; i <= 2 * N; i++) if (mark[i] == 0) s.insert(i);

    for (int i = 0; i < M; i++) {
        if (bucket[i].size() >= 2 && bucket[i][0].block != 1) pq.push({bucket[i][0].block, i});
    }

    while (pq.size()) {
        pii t = pq.top();
        pq.pop();
        int add = *s.rbegin();
        if (add < t.first) {
            cout << "NO";
            return;
        }
        bucket[t.second][1].block = add;
        s.erase(add);
    }

    for (int i = 0; i < M; i++) {
        if (bucket[i][0].block == 1) {
            if (bucket[i].size() >= 2) {
                bucket[i][1].block = *s.begin();
                s.erase(bucket[i][1].block);
            }

            while (s.size()) {
                int add = *s.begin();
                s.erase(add);

                char c;
                if (bucket[i].back().player == 'A') c = 'B';
                else c = 'A';

                bucket[i].push_back({c, "CHAIN", add});
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < bucket[i].size(); j++)
            cout << bucket[i][j].player << " " << bucket[i][j].act << " " << bucket[i][j].block << '\n';
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