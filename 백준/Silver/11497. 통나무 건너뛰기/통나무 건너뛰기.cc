#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int T, N, ans;
int logs[10000];

int diff(int A, int B) {
	if (A > B) return A - B;
	else return B - A;
}

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		ans = 0;
		deque <int> arr;
		for (int j = 0; j < N; j++) cin >> logs[j];
		sort(logs, logs + N);
		for (int j = N - 1; j >= 0; j--) {
			if (j % 2 == 0) arr.push_back(logs[j]);
			else arr.push_front(logs[j]);
		}
		ans = diff(arr[0], arr[N - 1]);
		for (int j = 1; j < N; j++) ans = max(ans, diff(arr[j], arr[j - 1]));
		cout << ans << '\n';
	}
	return 0;
}