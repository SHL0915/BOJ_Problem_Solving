#include <iostream>
using namespace std;

int R, C, N;
long long map[3001][3001];
long long table[3001][3001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, fuel;
        cin >> y >> x >> fuel;
        map[y][x] = fuel;
    }
    for (int i = R - 1; i >= 1; i--) {
        table[i][C] = table[i + 1][C] - 1;
        table[i][C] = min(table[i][C] + map[i][C], (long long)0);
    }
    for (int i = C - 1; i >= 1; i--) {
        table[R][i] = table[R][i + 1] - 1;
        table[R][i] = min(table[R][i] + map[R][i], (long long)0);
    }
    for (int i = R - 1; i >= 1; i--) {
        for (int j = C - 1; j >= 1; j--) {
            table[i][j] = max(table[i + 1][j] - 1, table[i][j + 1] - 1);           
            table[i][j] = min(table[i][j] + map[i][j], (long long)0);
        }
    }
    cout << 0 - table[1][1];
    return 0;
}