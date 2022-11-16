#include <iostream>
using namespace std;

string S, T;

string flip(string A);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S >> T;
	while (T.length() >= S.length()) {
		if (T == S) {
			cout << 1;
			return 0;
		}
		if (T.back() == 'A') T.erase(T.end() - 1);
		else {
			T.erase(T.end() - 1);
			T = flip(T);
		}
	}
	cout << 0;
	return 0;
}

string flip(string A) {
	string ret = "";
	for (int i = A.length() - 1; i >= 0; i--) ret += A[i];
	return ret;
}