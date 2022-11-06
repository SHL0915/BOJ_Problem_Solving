#include <iostream>
#include <vector>
using namespace std;

int N, K, ptr;
vector <char> arr;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++) arr[i] = '?';
	for (int i = 0; i < K; i++) {
		int change;
		char c;
		cin >> change >> c;
		ptr += change;
		ptr %= N;
		if (arr[ptr] == '?') arr[ptr] = c;		
		else if (arr[ptr] != c) {
			cout << "!";
			return 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] != '?' && arr[i] == arr[j]) {
				cout << '!';
				return 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[ptr];
		ptr--;
		if (ptr < 0) ptr += N;
	}
	return 0;
}