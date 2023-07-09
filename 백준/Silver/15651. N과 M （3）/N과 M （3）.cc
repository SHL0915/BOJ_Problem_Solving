#include <iostream>

using namespace std;

int N, M;
int output[10];
int mark[10]; // 이전까지 그 수를 사용을 했는가?

void BackTracking(int k) { // 칸을 M개를 비워서, 그 칸을 채울거야;
    if (k == M) {
        for (int i = 0; i < M; i++)
            cout << output[i] << " ";
        cout << '\n';
        return;
    }
    else { // 0 <= k <= (M - 1)
        for (int i = 1; i <= N; i++) {
            output[k] = i;
            BackTracking(k + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio();

    cin >> N >> M;

    BackTracking(0);

    return 0;
}