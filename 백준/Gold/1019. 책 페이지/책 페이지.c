#include <stdio.h>

long long N; /* 책 페이지의 개수 N. */
long long cnt[10]; /* 정답을 저장할 배열 cnt. */

void init() {
    for(int i = 0; i < 10; i++) cnt[i] = 0; /* 각 test case마다 정답을 담을 배열의 초기값을 0으로 설정. */
    scanf("%lld", &N); /* N을 입력받음. */
    return;
}

void calculate() {
    long long base = 1, accum = 0; /* 현재 k의 자리수를 처리하고 있다는 의미의 base, 여태까지 누적된 값 accum. 예를 들어, base = 1000이라면, 현재 천의 자리 수를 처리하고 있음을 뜻함. */
    
    while(N) { /* N을 10씩 나누어가며, N이 0이 아닐때까지 반복문을 진행한다. */
        int now = N % 10; /* 현재 자릿수에 해당하는 값 now */
        for(int i = 0; i < now; i++) cnt[i] += base * (N / 10 + 1); /* 0 ~ (now - 1) 까지의 수는 현재 N / 10 + 1 만큼 자릿수로서 등장한다. 이때, 각 자릿수에서는 base만큼 반복이 이루어지므로, cnt는 base * (N / 10 + 1) 만큼 증가한다. */
        for(int i = now; i < 10; i++) cnt[i] += base * (N / 10); /* now ~ 9 까지의 수는 현재 N / 10 만큼 자릿수로서 등장한다. 이때, 각 자릿수에서는 base만큼 반복이 이루어지므로, cnt는 base * (N / 10) 만큼 증가한다.  */
        cnt[now] += (accum + 1); /* now에서는 그보다 하위 자릿수의 값인 (accum + 1)만큼 추가로 수가 등장한다. */       
        cnt[0] -= base; /* 0 ~ 현재 자릿수의 앞에 들어있는 0은 count되지 않으므로 base만큼 빼준다. 예를 들어, 9에 대한 처리를 할때 이를 00009로 보지 않는다. */
        accum += base * now; /* 현재의 자릿수 now가 이전 자릿수로 변하여 accum에 더해진다. */
        N /= 10; /* N을 10으로 나누어 다음 자릿수에 대한 처리를 준비한다. */
        base *= 10; /* 자릿수는 하나 증가한다. */
    }

    return;
}

void output() {
    for(int i = 0; i < 10; i++) printf("%lld ", cnt[i]); /* 0 ~ 9까지 계산한 정답을 출력함. */
    printf("\n"); /* test case를 구분할 개행문자 출력. */
    return;
}

int main (void) {
    long long T = 1; /* test case의 개수를 저장하는 변수 T */
    //scanf("%lld", &T); /* test case의 개수를 입력 받음. */
    while(T--) {
        init(); /* test case마다 N을 입력받고, cnt 배열을 초기화시킴 */
        calculate(); /* test case마다 입력받은 N에 대하여 계산을 진행 */
        output(); /* test case마다 계산한 정답을 출력함 */
    }
    return 0;
}