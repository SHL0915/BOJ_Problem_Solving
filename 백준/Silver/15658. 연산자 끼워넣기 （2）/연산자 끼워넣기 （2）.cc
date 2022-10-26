#include <iostream>
#include <algorithm>
using namespace std;

int N;
int num[11];
int oper[10];
int A, B, C, D;
int min_ans = 1000000000, max_ans = -1000000000;

void BackTracking(int k, int A, int B, int C, int D);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	cin >> A >> B >> C >> D;
	BackTracking(0, A, B, C, D);
	cout << max_ans << '\n' << min_ans;
	return 0;
}

void BackTracking(int k, int A, int B, int C, int D) {
	if (k == N - 1) {
		int sum = num[0];
		for (int i = 0; i < N - 1; i++) {
			switch (oper[i]) {
			case 0: sum += num[i + 1]; break;
			case 1: sum -= num[i + 1]; break;
			case 2: sum *= num[i + 1]; break;
			case 3: sum /= num[i + 1]; break;
			}
		}
		min_ans = min(min_ans, sum);
		max_ans = max(max_ans, sum);
		return;
	}
	else {
		if (A > 0) {
			oper[k] = 0;
			BackTracking(k + 1, A - 1, B, C, D);
		}
		if (B > 0) {
			oper[k] = 1;
			BackTracking(k + 1, A, B - 1, C, D);
		}
		if (C > 0) {
			oper[k] = 2;
			BackTracking(k + 1, A, B, C - 1, D);
		}
		if (D > 0) {
			oper[k] = 3;
			BackTracking(k + 1, A, B, C, D - 1);
		}
	}
}