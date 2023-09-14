#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N, M, SZ;
int pi[1000005], seg[2000005];
pii wanted[1000005];

void update(int pos, int val) {
    for (seg[pos += SZ] += val; pos > 0; pos >>= 1) seg[pos >> 1] = seg[pos] + seg[pos ^ 1];
    return;
}

int query(int l, int r) {
    r++;
    int ret = 0;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += seg[l++];
        if (r & 1) ret += seg[--r];
    }
    return ret;
}

bool check(int i, int j, vector<int> &A) {
    int al = query(1, A[i]), ar = query(A[i], SZ);
    return (al == wanted[j].first && ar == wanted[j].second);
}

void make_pi(vector<int> &A) {
    fill(seg, seg + 2 * SZ + 5, 0);
    for (int i = 1, j = 0; i < N; i++) {
        update(A[i], 1);
        while (j && !check(i, j, A)) {
            int pos = i - j;
            j = pi[j - 1];
            int npos = i - j;
            for (int k = pos; k < npos; k++) update(A[k], -1);
        }
        if (check(i, j, A)) pi[i] = ++j;
        else update(A[i], -1);
    }
    return;
}

vector<int> kmp(vector<int> &A) {
    fill(seg, seg + 2 * SZ + 5, 0);
    vector<int> ret;
    for (int i = 0, j = 0; i < M; i++) {
        update(A[i], 1);
        while (j && !check(i, j, A)) {
            int pos = i - j;
            j = pi[j - 1];
            int npos = i - j;
            for (int k = pos; k < npos; k++) update(A[k], -1);
        }
        if (check(i, j, A)) {
            if (j == N - 1) {
                int pos = i - j;
                int npos = i + 1 - pi[j];
                j = pi[j];
                ret.push_back(pos + 1);
                for (int k = pos; k < npos; k++) update(A[k], -1);
            } else j++;
        } else update(A[i], -1);
    }
    return ret;
}


void solve() {
    cin >> N >> M;
    SZ = max(N, M);
    vector<int> pattern(N + 5), arr(M + 5);
    fill(seg, seg + 2 * SZ + 5, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        pattern[a - 1] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        update(pattern[i], 1);
        wanted[i] = {query(1, pattern[i]), query(pattern[i], SZ)};
    }

    vector<int> val;
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        val.push_back(arr[i]);
    }

    sort(val.begin(), val.end());
    for (int i = 0; i < M; i++) arr[i] = lower_bound(val.begin(), val.end(), arr[i]) - val.begin() + 1;

    make_pi(pattern);
    vector<int> ans = kmp(arr);

    cout << ans.size() << '\n';
    for (int a: ans) cout << a << " ";

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