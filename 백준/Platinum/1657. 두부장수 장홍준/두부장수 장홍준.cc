#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N, M;
char arr[20][20];
int val[150][150];
int table[20][20][(1 << 16)];

void putval();
int DP(int x, int y, int state);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    putval();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) arr[i][j] = s[j];
    }      
    memset(table, -1, sizeof(table));
    cout << DP(0, 0, 0);
    return 0;
}

int DP(int x, int y, int state) {
    if (state & 1) return DP((x + 1) % M, y + (x + 1) / M, state >> 1);
    if (x == M && y == N) return 0;
    int& ret = table[x][y][state];
    if (ret != -1) return ret;
    ret = 0;
    ret = max(ret, DP((x + 1) % M, y + (x + 1) / M, state >> 1));
    if (x < M - 1 && (state & (1 << 1)) == 0) ret = max(ret, val[arr[y][x]][arr[y][x + 1]] + DP((x + 2) % M, y + (x + 2) / M, state >> 2));
    if (y < N - 1) ret = max(ret, val[arr[y][x]][arr[y + 1][x]] + DP((x + 1) % M, y + (x + 1) / M, (state + (1 << M)) >> 1));    
    return ret;
}

void putval() {
    val['A']['A'] = 10;
    val['A']['B'] = 8;
    val['A']['C'] = 7;
    val['A']['D'] = 5;
    val['A']['F'] = 1;
    val['B']['A'] = 8;
    val['B']['B'] = 6;
    val['B']['C'] = 4;
    val['B']['D'] = 3;
    val['B']['F'] = 1;
    val['C']['A'] = 7;
    val['C']['B'] = 4;
    val['C']['C'] = 3;
    val['C']['D'] = 2;
    val['C']['F'] = 1;
    val['D']['A'] = 5;
    val['D']['B'] = 3;
    val['D']['C'] = 2;
    val['D']['D'] = 2;
    val['D']['F'] = 1;
    val['F']['A'] = 1;
    val['F']['B'] = 1;
    val['F']['C'] = 1;
    val['F']['D'] = 1;
    return;
}