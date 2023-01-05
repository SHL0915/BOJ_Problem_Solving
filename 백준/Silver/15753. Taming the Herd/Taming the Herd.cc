#include <bits/stdc++.h>
using namespace std;

int N, m, cnt, pre;
int arr[101];
int A[101];
int B[101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	A[0] = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] >= 0) {
			if (i - arr[i] < pre || i - arr[i] < 0 || B[i - arr[i]] == 1) {
				cout << -1;
				return 0;
			}
			else {
				pre = i - arr[i];
				A[pre] = 1;
				for (int j = 1; j <= arr[i]; j++) B[pre + j] = 1;
			}
		}		
	}
	for (int i = 0; i < N; i++) {
		if (A[i] == 1) m++;
		if (B[i] == 0 && A[i] == 0) cnt++;
	}
	cout << m << " " << m + cnt;
	return 0;
}