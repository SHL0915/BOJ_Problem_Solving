#include <iostream>
using namespace std;

int N, cnt;
int room[1000005];
int temp[1000005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> room[i];
	for (int i = 0; i < N; i++) {
		if (temp[i] != room[i]) {
			cnt++;
			for (int j = 0; j < 3; j++) {
				temp[i + j] ++;
				temp[i + j] %= 2;
			}
		}
	}
	cout << cnt;
	return 0;
}