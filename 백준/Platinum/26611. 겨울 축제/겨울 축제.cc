#include <bits/stdc++.h>
using namespace std;

int N, M, K, flag;
vector <int> arr, add;

void func(int pos);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	arr.resize(N + 1);
	add.resize(N + 1);
	for (int i = 0; i <= N; i++) cin >> arr[i];
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] / K) {
			if (i == arr.size() - 1) {
				add.push_back(arr[i] / K);
				arr.push_back(arr[i] / K);
			}
			else {
				add[i + 1] = arr[i] / K;
				arr[i + 1] += add[i + 1];
			}			
			arr[i] %= K;
		}		
	}
	func(arr.size() - 1);
	if (flag == 0) cout << 0;
	return 0;
}

void func(int pos) {
	if (pos == -1) return;
	int out = arr[pos] / M;
	if (out) {
		cout << out;
		flag = 1;
	}
	else if (flag) cout << 0;
	if (pos > 0) arr[pos - 1] += min(arr[pos] % M, add[pos]) * K;
	func(pos - 1);
	return;
}