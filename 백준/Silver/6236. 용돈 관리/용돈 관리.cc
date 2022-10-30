#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int money[100000];
long long max_val, sum, ans;

long long BinarySearch(long long left, long long right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		max_val = max(max_val, (long long)money[i]);
		sum += money[i];
	}
	ans = BinarySearch(max_val, sum);
	cout << ans;
	return 0;
}

long long BinarySearch(long long left, long long right) {
	long long mid = (left + right) / 2;
	if (left < right) {
		int cnt = 0;
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (temp < money[i]) {
				cnt++;
				temp = mid;
			}
			temp -= money[i];
		}
		if (cnt > M) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid);
	}
	else return mid;
}