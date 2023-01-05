#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[500001];
pair <int, int> temp[500001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		temp[i] = { arr[i], i };
	}
	stable_sort(temp, temp + N);
	for (int i = 0; i < N; i++) ans = max(ans, temp[i].second - i);
	cout << ans + 1;
	return 0;
}