#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M;
int A[100005], B[100005], arr[100005], pi[100005];

void make_pi() {
    for (int i = 1, j = 0; i < M; i++) {
        while (j && arr[i] != arr[j]) j = pi[j - 1];
        if (arr[i] == arr[j]) pi[i] = ++j;
    }
    return;
}

void solve() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i], A[i + N] = A[i];
    for (int i = 0; i < 2 * N; i++) B[i] = A[2 * N - 1 - i];

    for (int i = 0; i < M; i++) cin >> arr[i];

    make_pi();

    int a = 0, b = 0;

    for (int i = 0, j = 0; i < 2 * N; i++) {
        while (j && A[i] != arr[j]) j = pi[j - 1];
        if (A[i] == arr[j]) {
            if (j == M - 1) a++, j = pi[j];
            else j++;
        }
    }

    for (int i = 0, j = 0; i < 2 * N; i++) {
        while (j && B[i] != arr[j]) j = pi[j - 1];
        if (B[i] == arr[j]) {
            if (j == M - 1) a++, j = pi[j];
            else j++;
        }
    }

    if (a | b) cout << 1;
    else cout << 0;

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