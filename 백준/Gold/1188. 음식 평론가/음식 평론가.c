#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int ans = M;
    int now = 0;
    for (int i = 1; i <= M; i++) {
        if (now % M == 0) ans--;
        now += N;
    }

    printf("%d", ans);
    return 0;
}