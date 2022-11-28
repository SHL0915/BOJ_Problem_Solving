#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int arr[501];
int psum[501];
int table[1000001];
vector <int> primeNum;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	table[0] = 1;
	table[1] = 1;
	for (long long i = 2; i <= 1000000; i++) {
		if (table[i] == 0) {
			primeNum.push_back(i);
			for (long long j = i * i; j <= 1000000; j += i) table[j] = 1;
		}
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = 0; ; i++) {
		if (primeNum[i] > N) break;
		for (int j = 1; j <= N - primeNum[i] + 1; j++) {
			if (table[psum[j + primeNum[i] - 1] - psum[j - 1]] == 0) cnt++;
		}
	}
	cout << cnt;
	return 0;
}