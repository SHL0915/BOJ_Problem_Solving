#include <iostream>
#include <algorithm>
using namespace std;

int T, J, N;
int box[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans = 0;
		cin >> J >> N;
		for (int j = 0; j < N; j++) {
			int R, C;
			cin >> R >> C;
			box[j] = R * C;
		}
		sort(box, box + N);
		for (int j = N - 1; j >= 0; j--) {
			if (J <= 0) break;
			ans++;
			J -= box[j];
		}
		cout << ans << "\n";
	}
	return 0;
}