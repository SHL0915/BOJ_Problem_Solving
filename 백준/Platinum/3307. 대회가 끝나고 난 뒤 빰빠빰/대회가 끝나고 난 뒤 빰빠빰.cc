#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

struct stackData {
	double X, R;
};

int main(void) {	
	stack <stackData> s, temp;
	double x, r, min, rad, X, R;
	int N, i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%lf %lf", &x, &r);
		min = r;
		while (s.size() != 0) {
			X = s.top().X;
			R = s.top().R;
			rad = ((x - X) * (x - X)) / (4 * R);
			if (min >= rad)
				min = rad;
			if (min < R)
				break;
			else
				s.pop();
		}
		s.push({ x,min });
		printf("%.6lf\n",min);
	}
	return 0;
}