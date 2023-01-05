#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[(1 << 21)];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> K;
	int jump = N / K;
	for (int i = 0; i < N; i += jump) sort(arr + i, arr + i + jump);
	for (int i = 0; i < N; i++) cout << arr[i] << ' ';
	return 0;
}