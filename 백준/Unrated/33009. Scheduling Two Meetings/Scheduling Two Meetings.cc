#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int N, M;
int arr[200005];
int dp[(1 << 21)];

void solve() {
    cin >> N >> M;

    memset(dp, -0x3f, sizeof(dp));

    int zz = 0;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ll now = 0;
        for(int j = 0; j < s.length(); j++) {
            if(s[j] == 'Y') now += (1 << j);
        }
        arr[i] = now;
        now = ((1 << M) - 1) ^ now;
        if(now == 0) zz = 1;
        dp[now] = max(dp[now], 0);
    }

    if(zz == 1) {
        int a = -1, b = -1;
        for(int i = 0; i < N; i++) {
            if(arr[i] == ((1 << M) - 1)) {
                a = i;
                break;
            }
        }

        int ans = -1;
        for(int i = 0; i < N; i++) {
            if (i == a) continue;
            int flag = 0, cnt = 0;
            for(int j = 0; j < M; j++) {
                int f = arr[a] & (1 << j), s = arr[i] & (1 << j);
                if(!f && !s) {
                    flag = 1;
                    break;
                }
                if(f && s) cnt++;
            }        
            if(cnt > ans) {
                b = i;
                ans = cnt;
            }
        }

        if(a > b) swap(a, b);

        cout << a + 1 << " " << b + 1;
        return;
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < (1 << M); j++) {
            if(j & (1 << i)) dp[j] = max(dp[j], dp[j ^ (1 << i)] + 1);
        }
    }

    int ans = -1, a = -1, b = -1;
    for(int i = 0; i < N; i++) {
        int now = arr[i];
        if(dp[now] > ans) {
            a = i;
            ans = dp[now];
        }
    }

    if(ans < 0) {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (i == a) continue;
        int flag = 0, cnt = 0;
        for(int j = 0; j < M; j++) {
            int f = arr[a] & (1 << j), s = arr[i] & (1 << j);
            if(!f && !s) {
                flag = 1;
                break;
            }
            if(f && s) cnt++;
        }        
        if(flag) continue;
        if(cnt == ans) {
            b = i;
            break;
        }
    }

    cout << a + 1 << " " << b + 1;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}