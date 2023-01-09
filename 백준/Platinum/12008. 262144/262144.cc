#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[262145];
int table[262145][61];

int DP(int pos, int k);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    memset(table, -1, sizeof(table));
    for (int i = 60; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (DP(j, i) != 0) ans = max(ans, i);
        }
    }
    cout << ans;
    return 0;
}

int DP(int pos, int k) {
    if (k == arr[pos]) return pos + 1;
    if (pos == N) return 0;
    int& ret = table[pos][k];
    if (ret != -1) return ret;
    ret = 0;
    int temp = DP(pos, k - 1);
    if (temp > pos) ret = DP(temp, k - 1);    
    return ret;
}