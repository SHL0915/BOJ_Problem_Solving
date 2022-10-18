#include <iostream>
using namespace std;

int N;
int arr[10];
int mark[10];
int line[10];

void BackTracking(int n);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	BackTracking(0);
	return 0;
}

void BackTracking(int n) {	
	if (n == N) {
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < i; j++) if (line[j] > line[i]) cnt++;
			if (cnt != arr[line[i]]) return;
		}
		for (int i = 0; i < N; i++) cout << line[i] + 1 << " ";
		exit(0);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (mark[i] == 0) {
				line[n] = i;
				mark[i] = 1;
				BackTracking(n + 1);
				mark[i] = 0;
			}
		}
	}
}