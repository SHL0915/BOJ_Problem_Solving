#include <bits/stdc++.h>
using namespace std;

int N, now;
pair<int, int> arr[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		if (arr[i].first > now) now = arr[i].first;
		now += arr[i].second;
	}
	cout << now;
	return 0;
}