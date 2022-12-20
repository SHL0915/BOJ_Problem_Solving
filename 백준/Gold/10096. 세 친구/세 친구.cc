#include <bits/stdc++.h>
using namespace std;

int N;
string S;
set <string> arr;

void check(int type);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> S;
	if (N % 2 == 0) {
		cout << "NOT POSSIBLE";
		return 0;
	}
	for (int i = 0; i < 3; i++) check(i);	
	if (arr.size() == 0) cout << "NOT POSSIBLE";
	else if (arr.size() >= 2) cout << "NOT UNIQUE";			
	else if (arr.size() == 1) cout << (*arr.begin());
	return 0;
}

void check(int type) {
	string temp = "";
	int flag = 0;
	if (type == 0) {
		for (int i = 0; i + flag <= N / 2; i++) {
			if (S[i + flag] != S[i + N / 2 + 1]) {
				if (flag == 0) {
					flag = 1;
					i--;
					continue;
				}
				else return;
			}
			temp += S[i + flag];
		}
		arr.insert(temp);
	}
	else if (type == 1) {
		for (int i = 0; i < N / 2; i++) {
			if (S[i] != S[i + N / 2 + flag]) {
				if (flag == 0) {
					flag = 1;
					i--;
					continue;
				}
				else return;
			}
			temp += S[i + N / 2 + flag];
		}
		arr.insert(temp);
	}
	else {
		for (int i = 0; i < N / 2; i++) {
			if (S[i] != S[i + N / 2 + 1]) return;
			temp += S[i];
		}
		arr.insert(temp);
	}
}