#include <stdio.h>

int main(void) {
    long long G;
    scanf("%lld", &G);

    int cnt = 0;

    for (long long i = 1; i <= 100000; i++) {
        long long a = i * i;
        if (a - (i - 1) * (i - 1) > G) break;
        long long b = a - G;
        if (b <= 0) continue;

        long long k = 0;
        for (; k * k < b; k++);

        if (k * k != b) continue;
        printf("%lld\n", i);
        cnt++;
    }

    if (cnt == 0) {
        printf("-1");
        return 0;
    }

    return 0;
}