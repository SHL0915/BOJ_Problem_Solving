#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int A[50];
int B[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(A, A + N);
	sort(B, B + N);
	for (int i = 0; i < N; i++) ans += A[i] * B[N - 1 - i];
	cout << ans;
	return 0;
}