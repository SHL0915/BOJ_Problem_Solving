#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ans;
int arr[500000];
pair<int, int> copyArr[500000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		copyArr[i] = { arr[i],i };
	}
	stable_sort(copyArr, copyArr + N);
	for (int i = 0; i < N; i++) ans = max(ans, copyArr[i].second - i);
	cout << ans + 1;
	return 0;
}