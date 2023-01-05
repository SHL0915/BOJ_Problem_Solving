#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 0; i < N; i++) cout << arr[i] << '\n';
	return 0;
}