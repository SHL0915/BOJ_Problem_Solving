#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int arr[22] = { 5, 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20 };
double dp[505][505][2], check_dp[25][25][2];

double check_DP(int a, int b, int t, int org_a, int org_b, double x) {
    double & ret = check_dp[a][b][t];
    if (ret != -1) return ret;
    ret = 0.0;
    
    if (t == 0) {
        for (int i = 1; i <= 20; i++) {
            int na = a - i;
            if (na < 0) na = a;
            ret += check_DP(na, b, 1, org_a, org_b, x) / 20.0;
        }
    }
    else {
        double val = 1.0;
        for (int i = 1; i <= 20; i++) {
            double nxt = 0;
            for (int j = -1; j <= 1; j++) {
                int nb = b - arr[i + j];
                if (nb < 0) nb = b;
                if (a == org_a && nb == org_b) nxt += x / 3.0;
                else nxt += check_DP(a, b - arr[i + j], 0, org_a, org_b, x) / 3.0;
            }
            val = min(val, nxt);
        }
        ret = val;
    }
    
    return ret;
}

bool check(int a, int b, double x) {
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            check_dp[i][j][0] = dp[i][j][0];
            check_dp[i][j][1] = dp[i][j][1];
        }
    }
    
    double res = check_DP(a, b, 0, a, b, x);
    
    if (res > x) return false;
    else return true;
}

double DP(int a, int b, int t) {
    double & ret = dp[a][b][t];
    if (ret != -1) return ret;
    ret = 0;
    
    if (t == 0) {
        for (int i = 1; i <= 20; i++) {
            int na = a - i;
            if(na < 0) na = a;
            ret += DP(na, b, 1) / 20.0;
        }
    }
    else {
        double val = 1.0;
        for (int i = 1; i <= 20; i++) {
            double nxt = 0;
            for (int j = -1; j <= 1; j++) {
                int nb = b - arr[i + j];
                if(nb < 0) nb = b;
                nxt += DP(a, nb, 0) / 3.0;
            }
            val = min(val, nxt);
        }
        ret = val;
    }
    
    return ret;
}

void solve() {
    cout << DP(N, N, 0) << " " << 1.0 - DP(N, N, 1) << '\n';
    return;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(12);
    int t = 1;
    //cin >> t;
    for (int i = 0; i < 505; i++) {
        for (int j = 0; j < 505; j++) dp[i][j][0] = dp[i][j][1] = -1;
    }
    
    for (int i = 0; i < 505; i++) {
        dp[0][i][0] = dp[i][0][0] = 0;
        dp[0][i][1] = dp[i][0][1] = 1;
    }
    
    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            double l = 0.0, r = 1.0;
            int cnt = 1000;
            while (cnt--) {
                double mid = (l + r) / 2;
                if (check(i, j, mid)) r = mid;
                else l = mid;
            }
            dp[i][j][0] = check_dp[i][j][0];
            dp[i][j][1] = check_dp[i][j][1];
        }
    }
    while (1) {
        cin >> N;
        if (N == 0) break;
        solve();
    }
    return 0;
}