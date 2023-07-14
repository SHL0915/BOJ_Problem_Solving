#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int A[1000005], B[1000005];

int chk(int k) {
    int a = 0, b = 0;
    int aidx = 0, bidx = 0;
    while (1) {
        if (aidx >= N || bidx >= N) break;
        if (abs(A[aidx] - B[bidx]) <= k) {
            aidx++;
            bidx++;
        } else {
            if (A[aidx] > B[bidx]) {
                if (b == 1) return 0;
                else {
                    b = 1;
                    bidx++;
                }
            } else {
                if (a == 1) return 0;
                else {
                    a = 1;
                    aidx++;
                }
            }
        }
    }
    return 1;
}

int find_ans(int k) {
    int a = 0, b = 0;
    int aa = -1, bb = -1;
    int aidx = 0, bidx = 0;
    while (1) {
        if (aidx >= N || bidx >= N) break;
        if (abs(A[aidx] - B[bidx]) <= k) {
            aidx++;
            bidx++;
        } else {
            if (A[aidx] > B[bidx]) {
                b = 1;
                bb = bidx;
                bidx++;
            } else {
                a = 1;
                aa = aidx;
                aidx++;
            }
        }
    }
    if (a) {
        for (int i = aa - 1; i >= 0; i--) {
            if (abs(A[i + 1] - B[i]) > k) return A[i + 1];
        }
        return A[0];
    } else {
        int flag = 0;
        for (int i = 0; i < N; i++) {
            if (abs(A[i] - B[i]) > k) flag = 1;
        }
        if (flag == 0) return A[0];
        else {
            for (int i = N - 1; i >= 0; i--) {
                if (abs(A[i] - B[i]) > k) return A[i];
            }
        }
    }

    return -1;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A, A + N);
    sort(B, B + N);
    int l = 0, r = 1000000000;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (chk(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    assert(find_ans(ans) != -1);

    cout << find_ans(ans);
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