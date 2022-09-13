#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void){
	int W, H, X, Y, P,R;
	int i;
	int pos[2];
	int result = 0;

	int P_C_dis1, P_C_dis;


	scanf("%d %d %d %d %d", &W, &H, &X, &Y, &P);

	R = H / 2;

	for (i = 0; i < P; i++) {
		scanf("%d %d", &pos[0], &pos[1]);

		P_C_dis1 = (pos[0] - X) * (pos[0] - X) + (pos[1] - (Y + R)) * (pos[1] - (Y + R));
		P_C_dis = (pos[0] - (X+W)) * (pos[0] - (X+W)) + (pos[1] - (Y + R)) * (pos[1] - (Y + R));

		if (P_C_dis1 <= P_C_dis)
			P_C_dis = P_C_dis1;
		

		if ((pos[0] >= X) &&(pos[0] <= X + W) && (pos[1] <= Y + H) && (pos[1] >= Y)) {
			result += 1;
		}
		else
		{
			if (P_C_dis <= (R * R))
				result += 1;
		}

	}

	printf("%d", result);
}