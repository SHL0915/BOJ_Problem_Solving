#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int len;
int pi[1000005];
int idx[26], A[1000005], B[1000005];

bool f(int i, int j) {
    int a, b;
    if (A[i] == -1) a = INF;
    else a = i - A[i];
    if (A[j] == -1 || A[j] < j - i) b = INF;
    else b = j - A[j];

    return a == b;
}

bool g(int i, int j) {
    int a, b;
    if (A[i] == -1) a = INF;
    else a = i - A[i];
    if (B[j] == -1 || B[j] < j - i) b = INF;
    else b = j - B[j];

    return a == b;
}

void makePi(char P[]) {
    memset(idx, -1, sizeof(idx));
    memset(A, -1, sizeof(A));

    for (int i = 0; i < len; i++) {
        A[i] = idx[P[i] - 'a'];
        idx[P[i] - 'a'] = i;
    }

    int pos = 1, k = 0;

    while (pos + k < len) {
        if (f(k, pos + k)) {
            k++;
            pi[pos + k - 1] = k;
        } else {
            if (k == 0) pos++;
            else {
                pos += k - pi[k - 1];
                k = pi[k - 1];
            }
        }
    }

    return;
}


int findP(char T[], char P[], int N, int M) {
    int ret = 0;
    len = M;
    makePi(P);

    memset(idx, -1, sizeof(idx));
    memset(B, -1, sizeof(B));
    int pos = 0, k = 0;
    for (int i = 0; i < N; i++) {
        B[i] = idx[T[i] - 'a'];
        idx[T[i] - 'a'] = i;
    }

    while (pos + M <= N) {
        if (k < M && g(k, pos + k)) {
            k++;
            if (k == M) ret++;
        } else {
            if (k == 0) pos++;
            else {
                pos += k - pi[k - 1];
                k = pi[k - 1];
            }
        }
    }

    return ret;
}