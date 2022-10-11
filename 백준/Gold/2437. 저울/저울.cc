#include <iostream>
#include <algorithm>
using namespace std;

int N;
int weight[1000];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> weight[i];
	sort(weight, weight + N);
	if (weight[0] > 1) {
		cout << 1;
		return 0;
	}
	for (int i = 1; ; i++) {
		int temp = i;
		int flag = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (j == 0) {
				if (temp != weight[j]) flag = 1;
				break;
			}
			if (temp < weight[j]) continue;
			else if (temp == weight[j]) break;
			else {
				temp -= weight[j];
				if (temp <= weight[j - 1]) break;
			}
		}
		if (flag == 1) {
			cout << i;
			break;
		}
	}
	return 0;
}