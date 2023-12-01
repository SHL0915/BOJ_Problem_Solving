#include <stdio.h>
int T, H, W, N;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &H, &W, &N);
        N--;
		int XX(N / H+1), YY(N%H+1);
		printf("%d%02d\n", YY, XX);
	}
	return 0;
}