#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int K, N, yidx;
string S, ans;
string arr[1005];

int go_down(int y, int x) {
    if (y == N) return x;
    if (y == yidx) return x;
    
    int a = 0, b = 0;
    if (x != K - 1 && arr[y][x] == '-') a = 1;
    if (x != 0 && arr[y][x - 1] == '-') b = 1;
    
    if (a == 1) return go_down(y + 1, x + 1);
    if (b == 1) return go_down(y + 1, x - 1);
    
    return go_down(y + 1, x);
}

void solve() {
    cin >> K >> N;
    cin >> S;
    for (int i = 0; i < K - 1; i++) ans += '*';
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i].back() == '?') yidx = i;
    }
    
    string up, down;
    for (int i = 0; i < K; i++) up += '_', down += '_';
    for (int i = 0; i < K; i++) {
        up[go_down(0, i)] = (char) ('A' + i);
    }
    
    for (int i = 0; i < K; i++) {
        down[go_down(yidx + 1, i)] = up[i];
    }
    
    int pos[26], mark[26] = {0};
    for (int i = 0; i < K; i++) pos[up[i] - 'A'] = i;
    
    int flag = 0;
    for (int i = 0; i < K; i++) {
        if (down[i] == S[i]) continue;
        else {
            int a = down[i] - 'A', b = S[i] - 'A';
            if ((!mark[a] && !mark[b]) || (mark[a] == b && mark[b] == a)) {
                mark[a] = b;
                mark[b] = a;
                if (abs(pos[a] - pos[b]) != 1) flag = 1;
                else {
                    ans[min(pos[a], pos[b])] = '-';
                }
            } else flag = 1;
        }
    }
    
    if (flag) for (int i = 0; i < K - 1; i++) cout << "x";
    else cout << ans;
    
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