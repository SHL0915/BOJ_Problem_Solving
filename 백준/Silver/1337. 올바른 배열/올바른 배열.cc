#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, cnt, ans = 1234567890;
long long arr[50];
set <long long> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
	}
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for(int j = 0; j < 5; j++) {
			if (s.count(arr[i] + j) == 0) cnt++;
		}
		ans = min(ans, cnt);
	}
	cout << ans;
	return 0;
}