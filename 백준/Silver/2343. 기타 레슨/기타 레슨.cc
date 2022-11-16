#include <iostream>
#include <algorithm>
using namespace std;

int N, M, max_len;
int arr[100001];

int BinarySearch(int left, int right);

int main(void) {
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max_len = max(max_len, arr[i]);
	}
	int ans = BinarySearch(max_len, 1000000000);
	cout << ans;
	return 0;
}

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		int temp = 0, cnt = 1;
		for (int i = 0; i < N; i++) {
			temp += arr[i];
			if (temp > mid) {
				cnt++;
				temp = arr[i];
			}
		}
		if (cnt > M) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid);
	}
	else return left;
}