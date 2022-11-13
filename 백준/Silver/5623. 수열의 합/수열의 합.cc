#include <iostream>
using namespace std;

int N;
int arr[1000][1000];


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	if (N == 2) {
		cout << arr[1][0] / 2 << " " << arr[1][0] - (arr[1][0] / 2);
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (i < N - 2) cout << (arr[i][i + 1] - arr[i + 1][i + 2] + arr[i][i + 2]) / 2 << " ";
		else if (i == 1) cout << (arr[i][i + 1] - arr[i + 1][i - 1] + arr[i][i - 1]) / 2 << " ";
		else if (i >= 2)cout << (arr[i][i - 2] - arr[i - 2][i - 1] + arr[i][i - 1]) / 2 << " ";
	}
	return 0;
}