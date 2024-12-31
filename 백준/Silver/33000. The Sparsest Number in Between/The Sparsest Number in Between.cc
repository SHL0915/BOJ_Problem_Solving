#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int inf = 1e5;

ll a, b, ans;
string A, B;
int dp[64][2][2];
char path[64][2][2];

int DP(int now, int a, int b) {
    if(now == A.length()) return 0;
    int & ret = dp[now][a][b];
    if(~ret) return ret;
    ret = inf;

    int now_a = A[now] - '0', now_b = B[now] - '0';    
    int ff = inf, ss = inf;

    if(a == 0) {
        if(b == 0) {
            if(now_a == 1) {
                ret = min(ret, 1 + DP(now + 1, 0, b));
                ss = 1 + DP(now + 1, 0, b);
            }
            else {
                ret = min(ret, DP(now + 1, 0, b | (now_b == 1)));
                ff = DP(now + 1, 0, b | (now_b == 1));
                if(now_b != 0) {
                    ret = min(ret, 1 + DP(now + 1, 1, b));
                    ss = 1 + DP(now + 1, 1, b);
                }
            }
        }
        else {
            if(now_a == 1) {
                ret = min(ret, 1 + DP(now + 1, 0, b));
                ss = 1 + DP(now + 1, 0, b);
            }
            else {
                ret = min(ret, DP(now + 1, 0, b | (now_b == 1)));
                ff = DP(now + 1, 0, b | (now_b == 1));
                ret = min(ret, 1 + DP(now + 1, 1, b));
                ss = 1 + DP(now + 1, 1, b);
            }        
        }
    }
    else {
        if(b == 0) {
            ret = min(ret, DP(now + 1, a, b | (now_b == 1)));
            ff = DP(now + 1, a, b | (now_b == 1));
            if(now_b != 0) {
                ret = min(ret, 1 + DP(now + 1, a, b));
                ss = 1 + DP(now + 1, a, b);
            }           
        }
        else {
            ret = min(ret, DP(now + 1, a, b | (now_b == 1)));
            ff = DP(now + 1, a, b | (now_b == 1));
            ss = 1 + DP(now + 1, a, b); 
        }
    }

    if(ff <= ss) {
        path[now][a][b] = '0';
    }
    else {
        path[now][a][b] = '1';
    }

    return ret;
}

void solve() {
    cin >> a >> b;
    while(a) {
        if(a % 2) A += '1';
        else A += '0';
        a >>= 1;
    }
    reverse(A.begin(), A.end());

    while(b) {
        if(b % 2) B +='1';
        else B += '0';
        b >>= 1;
    }
    reverse(B.begin(), B.end());

    if(A.length() != B.length()) {
        int cnt = 0;
        for(int i = 0; i < A.length(); i++) if(A[i] == '1') cnt++;
        for(int i = 0; i < A.length(); i++) {
                ans *= 2;
                if(i == 0) ans++;
            }
        if(cnt != 1) ans *= 2;
        cout << ans;
    }
    else {
        memset(dp, -1, sizeof(dp));
        DP(0, 0, 0);

        int now = 0, f = 0, s = 0;
        string S;
        while(now < A.length()) {
            //cout << now << " " << f << " " << s <<  " " << path[now][f][s] << " " << endl;
            S += path[now][f][s];
            int ns = s, nf = f;
            if(A[now] == '0' && path[now][f][s] == '1') nf = f | 1;
            if(B[now] == '1' && path[now][f][s] == '0') ns = s | 1;
            now++;
            s = ns;
            f = nf;
        }

        for(int i = 0; i < S.length(); i++) {
            ans *= 2;
            if(S[i] == '1') ans++;
        }

        cout << ans;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}