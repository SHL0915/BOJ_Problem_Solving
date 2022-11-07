#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100000];
long long sum;

bool cmp(long long A, long long B) {
	return A > B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, cmp);
	for (int i = 1; i < N; i++) sum += arr[i];
	if (arr[0] > sum) cout << arr[0] - sum;
	else {
		if ((arr[0] + sum) % 2 == 0) cout << 0;
		else cout << 1;
	}
	return 0;
}