#include <bits/stdc++.h>
using namespace std;

long long N, ans;
long long arr[2000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		int l = 0, r = N - 1;
		while (1) {
			if (l == i) l++;
			if (r == i) r--;
			if (l >= r) break;
			if (arr[l] + arr[r] == arr[i]) {
                ans++;
				break;
			}
			if (arr[l] + arr[r] < arr[i]) l++;
			else r--;
		}		
	}
	cout << ans;
	return 0;
}