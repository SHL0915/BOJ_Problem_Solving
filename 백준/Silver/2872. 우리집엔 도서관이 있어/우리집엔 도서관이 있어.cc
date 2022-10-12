#include <iostream>
using namespace std;

int N, idx, temp, cnt;
int books[300000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> books[i];
		if (books[i] == N)
			idx = i;
	}
	temp = N;
	for (int i = idx; i >= 0; i--) {
		if (books[i] == temp) {
			cnt++;
			temp--;
		}
	}
	cout << N - cnt;
	return 0;
}