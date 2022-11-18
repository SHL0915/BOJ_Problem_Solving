#include <iostream>
#include <algorithm>
using namespace std;

int N, l_pos, r_pos, ans;
pair<int, int> ans_pos;
int arr[100000];

int absol(int A) {
	if (A >= 0) return A;
	else return -1 * A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	l_pos = 0; r_pos = N - 1;
	ans = absol(arr[l_pos] + arr[r_pos]);
	ans_pos = { l_pos, r_pos };
	while (l_pos < r_pos) {
		if (ans > absol(arr[l_pos] + arr[r_pos])) {
			ans = absol(arr[l_pos] + arr[r_pos]);
			ans_pos = { l_pos, r_pos };
		}
		if (arr[l_pos] + arr[r_pos] > 0) r_pos--;
		else l_pos++;
	}
	cout << arr[ans_pos.first] + arr[ans_pos.second];
	return 0;
}