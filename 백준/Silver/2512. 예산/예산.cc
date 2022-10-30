#include <iostream>
#include <algorithm>
using namespace std;

int N, max_num;
int district[10000];
long long sum, M, ans;

long long BinarySearch(long long left, long long right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> district[i];
		sum += district[i];
		max_num = max(max_num, district[i]);
	}
	cin >> M;
	if (M >= sum) cout << max_num;
	else {
		ans = BinarySearch(1, max_num);
		long long temp = 0;
		for (int i = 0; i < N; i++) {
			if (district[i] <= ans) temp += district[i];
			else temp += ans;
		}
		if (temp <= M) cout << ans;
		else cout << ans - 1;
	}
	return 0;
}

long long BinarySearch(long long left, long long right) {
	long long mid = (left + right) / 2;
	if (left < right) {
		long long temp = 0;
		for (int i = 0; i < N; i++) {
			if (district[i] <= mid) temp += district[i];
			else temp += mid;
		}
		if (temp > M) return BinarySearch(left, mid - 1);
		else return BinarySearch(mid + 1, right);
	}
	else return mid;
}