#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

int len;
int pi[1000005];
int id[26], rev[26];
int org[1000005];
deque<int> dq[26];

void srt() {
    sort(id, id + 26, [&](int a, int b) {
        if (dq[a].size() == 0) return false;
        if (dq[b].size() == 0) return true;
        return dq[a].front() < dq[b].front();
    });

    for (int i = 0; i < 26; i++) rev[id[i]] = i;
}

void makePi(char P[]) {
    for (int i = 0; i < 26; i++) id[i] = i;

    int pos = 1, k = 0;
    for (int i = 0; i < len; i++) dq[P[i] - 'a'].push_back(i);
    srt();

    for (int i = 0; i < len; i++) org[i] = rev[P[i] - 'a'];
    for (int i = 0; i < 26; i++) dq[i].clear();

    dq[P[1] - 'a'].push_back(1);
    srt();

    while (pos + k < len) {
        if (org[k] == rev[P[pos + k] - 'a']) {
            k++;
            if (pos + k < len) dq[P[pos + k] - 'a'].push_back(pos + k);
            srt();
            pi[pos + k - 1] = k;
        } else {
            if (k == 0) {
                dq[P[pos] - 'a'].pop_front();
                srt();
                pos++;
            } else {
                for (int i = 0; i < k - pi[k - 1]; i++) dq[P[pos + i] - 'a'].pop_front();
                srt();
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

    int pos = 0, k = 0;
    for (int i = 0; i < 26; i++) dq[i].clear();

    dq[T[0] - 'a'].push_back(0);
    srt();

    while (pos + M <= N) {
        if (k < M && org[k] == rev[T[pos + k] - 'a']) {
            k++;
            if(pos + k < N) dq[T[pos + k] - 'a'].push_back(pos + k);
            srt();
            if (k == M) ret++;
        } else {
            if (k == 0) {
                dq[T[pos] - 'a'].pop_front();
                srt();
                pos++;
            } else {
                for (int i = 0; i < k - pi[k - 1]; i++) dq[T[pos + i] - 'a'].pop_front();
                srt();
                pos += k - pi[k - 1];
                k = pi[k - 1];
            }
        }
    }

    return ret;
}