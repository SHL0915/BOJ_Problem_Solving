#include <iostream>
using namespace std;

int N;
int candy[1000];
int temp[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> candy[i];
	for (int i = 0; i <= 100000; i++) {
		temp[0] = i;
		for (int j = 0; j < N - 1; j++) temp[j + 1] = candy[j] - temp[j];
		if (candy[N - 1] - temp[N - 1] == i) break;
	}
	for (int i = 0; i < N; i++) cout << temp[i] << '\n';
	return 0;
}