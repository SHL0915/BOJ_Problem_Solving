#include <iostream>
using namespace std;

int T, N;
string S;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		S = "";
		for (int i = 0; i < N; i++) {
			char c;
			cin >> c;
			if (S.length() == 0) S += c;
			else {
				if (c <= S[0]) S = c + S;
				else S += c;
			}
		}
		cout << S << '\n';
	}
	return 0;
}