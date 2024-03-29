#include <bits/stdc++.h>
using namespace std;

int N, T, ans;
pair<int, int> arr[1000];

int BinarySearch(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> T;
	int msum = 0, Msum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		msum += arr[i].first;
		Msum += arr[i].second;
	}
	if (msum > T || Msum < T) {
		cout << -1;
		return 0;
	}
	cout << BinarySearch(0, 100000000000);
	return 0;
}

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		int flag = 0, sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i].first > mid) {
				flag = 1;
				break;
			}
			sum += min(mid, arr[i].second);
		}
		if (flag == 1) return BinarySearch(mid + 1, right);
		else {
			if (sum >= T) return BinarySearch(left, mid);
			else return BinarySearch(mid + 1, right);
		}
	}
	else return left;
}