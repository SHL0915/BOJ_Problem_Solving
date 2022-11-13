#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long arr[1000000];

long long Reverse(string A);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		arr[i] = Reverse(input);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) cout << arr[i] << '\n';
	return 0;
}

long long Reverse(string A) {
	long long ret = 0;
	long long degree = 1;
	for (int i = 0; i < A.size(); i++) {
		ret += (degree * (A[i] - '0'));
		degree *= 10;
	}
	return ret;
}