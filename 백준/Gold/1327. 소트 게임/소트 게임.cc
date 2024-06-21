#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, K, ans;
map<string, int> vst;
int arr[10];
queue<string> q;

string flip(string s, int pos) {
    string ret = "";
    for (int i = 0; i < pos; i++) ret += s[i];
    for (int i = pos + K - 1; i >= pos; i--) ret += s[i];
    for (int i = pos + K; i < s.length(); i++) ret += s[i];
    return ret;
}

void BFS() {
    string now = q.front();
    q.pop();
    
    int flag = 0;
    for (int i = 1; i < now.length(); i++) {
        if (now[i] < now[i - 1]) flag = 1;
    }
    
    if (!flag) {
        ans = min(ans, vst[now]);
        return;
    }
    
    for (int i = 0; i <= now.length() - K; i++) {
        string nxt = flip(now, i);
        if (vst.count(nxt)) continue;
        vst[nxt] = vst[now] + 1;
        q.push(nxt);
    }
    
    return;
}

void solve() {
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    string now = "";
    for (int i = 0; i < N; i++) now += (arr[i] + '0');
    
    ans = 0x3f3f3f3f;
    vst[now] = 0;
    q.push(now);
    while (q.size()) BFS();
    
    if (ans == 0x3f3f3f3f) cout << -1;
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