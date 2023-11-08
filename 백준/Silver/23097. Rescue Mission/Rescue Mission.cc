#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
vector<int> idx[15];
int arr[100005];
int psum[100005];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        psum[i] = (arr[i] + psum[i - 1]) % 10;
        idx[psum[i]].push_back(i);
    }
    
    for (int i = 1; i <= N; i++) {
        int now = psum[i - 1];
        int nxt = lower_bound(idx[now].begin(), idx[now].end(), i) - idx[now].begin();
        if(nxt == idx[now].size()) cout << -1 << " ";
        else cout << idx[now][nxt] - i + 1 << " ";
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