#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <string> list;

bool isNum(char c) {
	if (c >= '0' && c <= '9') return true;
	else return false;
}

bool cmp(string A, string B) {
	if (A.length() == B.length()) {
		for (int i = 0; i < A.length(); i++) {
			if (A[i] < B[i]) return true;
			else if (B[i] < A[i]) return false;
		}
	}
	return A.length() < B.length();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		string temp = "";
		for (int j = 0; j < input.size(); j++) {
			if (isNum(input[j]) == true) temp += input[j];
			else {
				if (temp.length() != 0) list.push_back(temp);
				temp = "";
			}
			while (temp.length() >= 2) {
				if (temp[0] == '0') temp.erase(temp.begin());
				else break;
			}
		}
		if (temp.length() != 0) list.push_back(temp);
	}
	sort(list.begin(), list.end(), cmp);
	for (int i = 0; i < list.size(); i++) cout << list[i] << '\n';
	return 0;
}