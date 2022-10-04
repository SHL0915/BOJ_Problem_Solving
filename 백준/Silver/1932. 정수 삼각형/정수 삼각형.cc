#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;
int arr[500][500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];			
		}
	}
	for (int i = 1; i < n; i++) {
		arr[i][0] += arr[i - 1][0];
		arr[i][i] += arr[i - 1][i - 1];
		for (int j = 1; j <= i - 1; j++) {
			arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}
	for (int i = 0; i < n; i++)
		ans = max(ans, arr[n - 1][i]);
	cout << ans;
	return 0;
}