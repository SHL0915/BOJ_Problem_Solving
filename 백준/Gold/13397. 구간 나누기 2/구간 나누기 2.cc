#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[5000];

int BinarySearch(int left, int right);
int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int ans = BinarySearch(0, 10000);
	cout << ans;
	return 0;
}

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		int min_num = arr[0], max_num = arr[0], cnt = 1;
		for (int i = 1; i < N; i++) {
			if (absol(arr[i] - min_num) > mid || absol(arr[i] - max_num) > mid) {
				min_num = arr[i];
				max_num = arr[i];
				cnt++;
			}
			min_num = min(min_num, arr[i]);
			max_num = max(max_num, arr[i]);
		}
		if (cnt > M) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid);
	}
	return left;
}