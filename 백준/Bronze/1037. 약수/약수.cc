#include <iostream>
#include <algorithm>
using namespace std;

int M;
int arr[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M;
	for (int i = 0; i < M; i++) cin >> arr[i];
	sort(arr, arr + M);
	cout << arr[0] * arr[M - 1];
	return 0;
}