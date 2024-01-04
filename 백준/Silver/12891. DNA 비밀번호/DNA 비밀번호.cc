#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
string S;
int arr[26], cnt[26];

void solve() {
    cin >> N >> M;
    cin >> S;
    cin >> arr['A' - 'A'] >> arr['C' - 'A'] >> arr['G' - 'A'] >> arr['T' - 'A'];
    
    for (int i = 0; i < M - 1; i++) {
        cnt[S[i] - 'A']++;
    }
    
    int ans = 0;
    for (int i = M - 1; i < N; i++) {
        cnt[S[i] - 'A']++;
        if (cnt[0] >= arr[0] && cnt[2] >= arr[2] && cnt[6] >= arr[6] && cnt[19] >= arr[19]) ans++;
        cnt[S[i - M + 1] - 'A']--;
    }
    
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