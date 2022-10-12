#include <iostream>
#include <algorithm>
using namespace std;

int N, maxCnt, cnt = 1;
int children[1000000];
int key[1000001];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> children[i];
		key[children[i]] = i;
	}
	for (int i = N; i >= 2; i--) {
		if (key[i] > key[i - 1]) cnt++;
		else {
			maxCnt = max(maxCnt, cnt);
			cnt = 1;
		}
	}
	cout << N - maxCnt;
	return 0;
}