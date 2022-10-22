#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int pos[1000];

int BinarySearch(int left, int right);
int Check(int start, int val);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) cin >> pos[i];
	if (K == 1) cout << N;
	else cout << BinarySearch(0, N) - 1;
	return 0;
}

int BinarySearch(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		int temp = 0;
		for (int i = 0; i < M; i++) temp += Check(i, mid);
		if (temp == 0) return BinarySearch(left, mid);
		else return	BinarySearch(mid + 1, right);
	}
	else return mid;
}

int Check(int start, int val) {
	int cnt = 0;
	int idx = start;
	for (int i = start; i < M; i++) {
		if (pos[i] - pos[idx] >= val) {
			cnt++;
			idx = i;
		}
	}
	if (pos[start] + N - pos[idx] >= val) cnt++;
	if (cnt >= K) return 1;
	else return 0;
}