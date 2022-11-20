#include <iostream>
#include <vector>
using namespace std;

long long N, M, K, X;
long long arr[100001];
long long newArr[100001];
vector <long long> tree;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K >> X;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		arr[i] += arr[i - 1];
		if (arr[i] + X < K) newArr[i] = 1;
	}
	for (int i = 1; i <= N; i++) newArr[i] += newArr[i - 1];
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << newArr[B - 1] - newArr[A - 1] << '\n';
	}
	return 0;
}