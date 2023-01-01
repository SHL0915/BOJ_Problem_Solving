#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int arr[11][2];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		if (arr[A][1]) {
			if (arr[A][0] != B) {
				cnt++;
				arr[A][0] = B;
			}
		}
		else {
			arr[A][1] = 1;
			arr[A][0] = B;
		}
	}
	cout << cnt;
	return 0;
}