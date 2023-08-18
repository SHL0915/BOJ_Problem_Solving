#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
int len;
int pi[1000005];
int org[1000005];

void makePi(char P[]) {
    vector<int> A[26], B[26];

    for (int i = 0; i < len; i++) {
        int c = P[i] - 'a';
        if (A[c].size() == 0) org[i] = INF;
        else org[i] = i - A[c].back();
        A[c].push_back(i);
    }

    int pos = 1, k = 0;

    while (pos + k < len) {
        int c = P[pos + k] - 'a';
        int now;
        if (B[c].size() == 0 || B[c].back() < pos) now = INF;
        else now = pos + k - B[c].back();
        if (org[k] == now) {
            B[c].push_back(pos + k);
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

    vector<int> A[26];
    int pos = 0, k = 0;

    while (pos + M <= N) {
        int c = T[pos + k] - 'a';
        int now;
        if (A[c].size() == 0 || A[c].back() < pos) now = INF;
        else now = pos + k - A[c].back();

        if (k < M && org[k] == now) {
            A[c].push_back(pos + k);
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