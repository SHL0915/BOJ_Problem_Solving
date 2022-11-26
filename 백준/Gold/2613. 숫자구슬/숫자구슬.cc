#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int arr[300];

int BinarySearch(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	ans = BinarySearch(1, 30000);
	cout << ans << '\n';
	int cnt = 0, temp = 0;
	for (int i = 0; i < N; i++) {
		temp += arr[i];
		if (temp > ans) {
			cout << cnt << " ";
			M--;
			temp = arr[i];
			cnt = 0;
		}	
		cnt++;		
		if (N - i == M) {
			cout << cnt << " ";
			M--;
			break;
		}
	}
	for (int i = 0; i < M; i++) cout << 1 << " ";
	return 0;
}

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		int cnt = 1, temp = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				cnt = 0x3f3f3f3f;
				break;
			}
			else if (arr[i] + temp > mid) {
				cnt++;
				temp = arr[i];
			}
			else temp += arr[i];
		}
		if (cnt > M) return BinarySearch(mid + 1, right);
		else return BinarySearch(left, mid);
	}
	else return left;
}