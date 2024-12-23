#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int org[100005];
int arr[100005];
int cnt[4][4];

int f(int a, int b) {
    int v = min(cnt[a][b], cnt[b][a]);
    cnt[a][b] -= v, cnt[b][a] -= v;
    return v;
}

int find_ans() {
    int temp[100005];
    for (int i = 0; i < N; i++) temp[i] = arr[i];
    sort(temp, temp + N);
    
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++) {
        if (arr[i] == temp[i]) continue;
        else cnt[temp[i]][arr[i]]++;
    }
    
    int ret = 0;
    ret += f(1, 2);
    ret += f(1, 3);
    ret += f(2, 3);
    
    int v = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) v = max(v, cnt[i][j]);
    }
    
    ret += 2 * v;
    
    return ret;
}

void solve() {
    cin >> N;
    
    for (int i = 0; i < N; i++) cin >> org[i];
    
    vector<int> v(3);
    for (int i = 0; i < 3; i++) v[i] = i + 1;
    
    int ans = 1e9;
    do {
        for (int i = 0; i < N; i++) arr[i] = v[org[i] - 1];
        ans = min(ans, find_ans());
    } while (next_permutation(v.begin(), v.end()));
    
    cout << ans;
    
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