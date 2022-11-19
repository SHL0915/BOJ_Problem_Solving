#include <iostream>
#include <algorithm>
using namespace std;

int N;
string arr[50];

bool cmp(string A, string B) {
	if (A.length() != B.length()) return A.length() < B.length();
	int sumA = 0, sumB = 0;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] >= '0' && A[i] <= '9') sumA += (A[i] - '0');
		if (B[i] >= '0' && B[i] <= '9') sumB += (B[i] - '0');
	}
	if (sumA == sumB) return A < B;
	else return sumA < sumB;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++) cout << arr[i] << '\n';
	return 0;
}