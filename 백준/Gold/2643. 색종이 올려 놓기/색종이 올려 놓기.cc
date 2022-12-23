#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> arr[100];
int table[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		arr[i] = { min(A,B), max(A,B) };
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		table[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j].second <= arr[i].second) table[i] = max(table[i], table[j] + 1);
		}
		ans = max(ans, table[i]);
	}
	cout << ans;
	return 0;
}