#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100000];
long long sum;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N - 1; i++) sum += arr[i];
	if (arr[N - 1] > sum) cout << arr[N - 1] - sum;
	else {
		if ((arr[N - 1] + sum) % 2 == 0) cout << 0;
		else cout << 1;
	}
	return 0;
}