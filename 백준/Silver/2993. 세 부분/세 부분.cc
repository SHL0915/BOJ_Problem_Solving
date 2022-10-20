#include <iostream>
#include <algorithm>
using namespace std;

string word, A, B, C, ans;
string result;

void func();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> word;
	ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
	for (int i = 0; i < word.size() - 2; i++) {
		for (int j = i + 1; j < word.size() - 1; j++) {
			A = "";
			B = "";
			C = "";
			for (int l = 0; l <= i; l++) A += word[l];
			for (int l = i + 1; l <= j; l++) B += word[l];
			for (int l = j + 1; l < word.size(); l++) C += word[l];
			func();
			ans = min(ans, result);
		}
	}
	cout << ans;
	return 0;
}

void func() {
	string temp = "";
	for (int i = A.size() - 1; i >= 0; i--) temp += A[i];
	A = temp;
	temp = "";
	for (int i = B.size() - 1; i >= 0; i--) temp += B[i];
	B = temp;
	temp = "";
	for (int i = C.size() - 1; i >= 0; i--) temp += C[i];
	C = temp;
	result = A + B + C;
	return;
}