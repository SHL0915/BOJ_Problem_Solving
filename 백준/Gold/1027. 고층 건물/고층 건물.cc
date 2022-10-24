#include <iostream>
using namespace std;

int N, ans;
long long Building[50];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> Building[i];
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		int flag;
		for (int j = 0; j < i; j++) {
			flag = 0;
			for (int k = j + 1; k < i; k++) {
				if ((Building[k] - Building[j]) * (i - j) >= (Building[i] - Building[j]) * (k - j)) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) cnt++;
		}
		for (int j = i + 1; j < N; j++) {
			flag = 0;
			for (int k = i + 1; k < j; k++) {
				if ((Building[k] - Building[i]) * (j - i) >= (Building[j] - Building[i]) * (k - i)) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}