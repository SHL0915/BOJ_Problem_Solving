#include <iostream>
using namespace std;

int N, max_num, max_cnt;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		int A = N;
		int B = i;
		int temp;
		while (1) {
			temp = A - B;
			if (temp < 0) break;
			cnt++;
			A = B;
			B = temp;
		}
		if (cnt >= max_cnt) {
			max_cnt = cnt;
			max_num = i;
		}
	}
	cout << max_cnt + 2 << '\n';
	int A = N;
	int B = max_num;
	int temp;
	cout << A << " " << B << " ";
	while (1) {
		temp = A - B;
		if (temp < 0) break;		
		A = B;
		B = temp;
		cout << temp << " ";
	}
	return 0;
}