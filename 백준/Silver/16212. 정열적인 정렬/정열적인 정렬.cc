#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[500000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) cout << arr[i] << " ";
	return 0;
}