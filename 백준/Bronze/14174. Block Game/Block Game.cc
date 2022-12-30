#include <bits/stdc++.h>
using namespace std;

int N;
int arr[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string A, B;
		cin >> A >> B;
		int Acnt[26] = { 0 };
		int Bcnt[26] = { 0 };
		for (int j = 0; j < A.length(); j++) Acnt[A[j] - 'a']++;
		for (int j = 0; j < B.length(); j++) Bcnt[B[j] - 'a']++;
		for (int j = 0; j < 26; j++) arr[j] += max(Acnt[j], Bcnt[j]);
	}
	for (int i = 0; i < 26; i++) cout << arr[i] << '\n';
	return 0;
}