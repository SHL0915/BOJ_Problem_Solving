#include <bits/stdc++.h>
using namespace std;

int N, ans;
pair<int, int> arr[100001];
set <int> s;

int absol(int A) {
	if (A > 0) return A;
	else return -A;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
		s.insert(i);
	}
	sort(arr, arr + N);
	for (int i = 0; i < N - 1; i++) {
		s.erase(arr[i].second);
		int l = absol(arr[i].second - *s.begin()) - 1;
		int r = absol(arr[i].second - *s.rbegin()) - 1;
		l *= arr[i].first;
		r *= arr[i].first;
		ans = max({ ans, l, r });
	}
	cout << ans;
	return 0;
}