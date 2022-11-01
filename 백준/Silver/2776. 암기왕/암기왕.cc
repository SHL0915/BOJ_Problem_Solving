#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M;
int memo1[1000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> memo1[i];
		sort(memo1, memo1 + N);
		cin >> M;
		for (int i = 0; i < M; i++) {
			int input;
			cin >> input;
			if (input > memo1[N - 1]) cout << "0\n";
			else if (memo1[lower_bound(memo1, memo1 + N, input) - memo1] == input) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}