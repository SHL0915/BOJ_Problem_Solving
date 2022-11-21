#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1234567890;

int L, K, C, max_len, min_len;
int pos[10001];
int logs[10005];

int BinarySearch(int left, int right);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> L >> K >> C;
	for (int i = 0; i < K; i++) cin >> pos[i];
	sort(pos, pos + K);
	logs[0] = pos[0];
	for (int i = 1; i < K; i++) logs[i] = (pos[i] - pos[i - 1]);
	logs[K] = L - pos[K - 1];
	for (int i = 0; i <= K; i++) max_len = max(max_len, logs[i]);
	min_len = BinarySearch(max_len, L);	
	cout << min_len << " ";
	for (int i = 0; i < K; i++) {
		if (pos[i] > min_len) break;
		int now = 0;
		int cnt = 0;
		for (int j = i + 1; j <= K; j++) {
			if (now + logs[j] > min_len) {
				cnt++;
				now = logs[j];
			}
			else now += logs[j];
		}
		if (cnt <= C - 1) {
			cout << pos[i];
			break;
		}
	}
	return 0;
}

int BinarySearch(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		int now = 0;
		for (int i = 0; i <= K; i++) {
			if (now + logs[i] > mid) {
				cnt++;
				now = logs[i];
			}
			else now += logs[i];
		}
		if (cnt <= C) return BinarySearch(left, mid);
		else return BinarySearch(mid + 1, right);

	}
	else return left;
}
