#include <bits/stdc++.h>
using namespace std;

int N, ans;
int arr[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (arr[i] < arr[i - 1]) ans = i - 1;
	}
	cout << ans;
	return 0;
}