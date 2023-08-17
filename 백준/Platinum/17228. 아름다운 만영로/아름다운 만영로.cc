#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, char>;

ll N, cnt;
set<int> ans;
string S, T;
vector<pii> tree[500005];
int pi[500005];
vector<int> idx;

void makePi(string s) {
    int n = s.length(), pos = 1, k = 0;
    while (pos + k < n) {
        if (s[pos + k] == s[k]) {
            k++;
            pi[pos + k - 1] = k;
        } else {
            if (k == 0) pos++;
            else {
                pos += (k - pi[k - 1]);
                k = pi[k - 1];
            }
        }
    }
    return;
}

void kmp(string s, string cmp) {
    int n = s.length(), m = cmp.length(), pos = 0, k = 0;
    while (pos + m <= n) {
        if (k < m && s[pos + k] == cmp[k]) {
            k++;
            if (k == m) ans.insert(idx[pos + m - 1]);
        } else {
            if (k == 0) pos++;
            else {
                pos += (k - pi[k - 1]);
                k = pi[k - 1];
            }
        }
    }
    return;
}

void DFS(int node) {
    cnt++;
    if (tree[node].size() == 0) kmp(T, S);

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        char c = tree[node][i].second;
        T += c;
        idx.push_back(cnt);
        DFS(next);
        T.pop_back();
        idx.pop_back();
    }

    return;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
    }
    cin >> S;
    makePi(S);

    DFS(1);

    cout << ans.size();
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