#include <iostream>
#include <algorithm>
using namespace std;

int N, ans, temp;
int arr[100000];
int table[100000][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	table[0][0] = 1;
	table[0][1] = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1]) {
			table[i][0] = table[i - 1][0] + 1;
			table[i][1] = table[i - 1][1] + 1;
		}
		else if (arr[i] > arr[i - 1]) {
			table[i][0] = table[i - 1][0] + 1;
			table[i][1] = 1;
		}
		else {
			table[i][0] = 1;
			table[i][1] = table[i - 1][1] + 1;
		}
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, table[i][0]);
		ans = max(ans, table[i][1]);
	}
	cout << ans;
	return 0;
}