#include <iostream>
#include <set>
using namespace std;

int N, ans;
string arr[50];
set <int> list[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < N; j++) if (arr[i][j] == 'Y') list[i].insert(j);
	}
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[i][j] == 'Y') cnt++;
			else {
				for (int k = 0; k < N; k++) {
					if (arr[j][k] == 'Y' && list[i].count(k) != 0) {
						cnt++;
						break;
					}
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}