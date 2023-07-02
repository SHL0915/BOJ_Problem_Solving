#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, R;
string arr[305];
map<string, int> convert;
set<int> s[305];
int val[305], A[305], B[305], mark[305], ans[305];
vector<int> graph[305];

int DFS(int node);

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        convert[arr[i]] = i;
        val[i] = 1;
    }

    cin >> R;
    for (int i = 0; i < R; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> v;
        for (int j = 0; j < a; j++) {
            string s;
            cin >> s;
            int c = convert[s];
            v.push_back(c);
            val[c] = max(val[c], b);
        }

        set<int> ss;
        if (s[b].size() == 0) {
            for (int c: v) s[b].insert(c);
        } else {
            for (int c: v) {
                if (s[b].count(c)) ss.insert(c);
            }
            swap(s[b], ss);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int a: s[i]) {
            if(val[a] == i) graph[a].push_back(i);
         }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    for (int i = 1; i <= N; i++) {
        if (A[i] == -1) {
            memset(mark, 0, sizeof(mark));
            DFS(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] != -1) ans[A[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] != -1) continue;
        else {
            for (int j = val[i]; j <= N; j++) {
                if (ans[j]) continue;
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] == -1) {
            memset(mark, 0, sizeof(mark));
            DFS(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (A[i] != -1) ans[A[i]] = i;
    }

    for (int i = 1; i <= N; i++) cout << arr[ans[i]] << " ";
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

int DFS(int node) {
    mark[node] = 1;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (B[next] == -1 || (mark[B[next]] == 0 && DFS(B[next]))) {
            A[node] = next;
            B[next] = node;
            return 1;
        }
    }
    return 0;
}