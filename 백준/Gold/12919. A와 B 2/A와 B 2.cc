#include <iostream>
using namespace std;

string A, B;

void BruteForce(string S);
string reverse(string S);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	BruteForce(B);
	cout << 0;
	return 0;
}

void BruteForce(string S) {
	if (S.length() == A.length()) {
		if (S == A) {
			cout << 1;
			exit(0);
		}
	}
	else {
		string temp;
		if (S.back() == 'A') {
			temp = S;
			temp.erase(temp.end() - 1);
			BruteForce(temp);
		}
		temp = reverse(S);
		if (temp.back() == 'B') {
			temp.erase(temp.end() - 1);
			BruteForce(temp);
		}
	}
}

string reverse(string S) {
	string ret = "";
	for (int i = 0; i < S.length(); i++) ret += S[S.length() - 1 - i];
	return ret;
}