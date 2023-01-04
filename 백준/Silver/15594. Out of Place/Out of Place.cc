#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int arr[100];
int sorted[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sorted[i] = arr[i];
	}
	sort(sorted, sorted + N);
	for (int i = 0; i < N; i++) {
		if (arr[i] == sorted[i]) continue;		
		for (int j = i + 1; j < N; j++) {
			if (arr[j] == sorted[i] && arr[j] != sorted[j]) {
				swap(arr[i], arr[j]);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}