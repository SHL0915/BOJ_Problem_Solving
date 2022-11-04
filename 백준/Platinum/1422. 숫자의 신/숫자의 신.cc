#include <iostream>
#include <algorithm>
using namespace std;

long long K, N;
long long arr[50];
long long priority[50];

bool cmp(long long A, long long B);
string ItoS(long long A);
long long StoI(string S);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		priority[i] = arr[i];
	}
	sort(arr, arr + K);
	sort(priority, priority + K, cmp);
	string ans = "";
	int flag = 0;
	for (int i = 0; i < K; i++) {
		if (priority[i] == arr[K - 1] && flag == 0) {
			flag = 1;
			for (int j = 0; j < N - K + 1; j++) ans += ItoS(priority[i]);
		}
		else ans += ItoS(priority[i]);
	}
	cout << ans;
	return 0;
}

bool cmp(long long A, long long B) {
	string S1 = ItoS(A);
	string S2 = ItoS(B);
	int Aptr = 0, Bptr = 0;
	for (int i = 0; i < 1000; i++) {
		if (Aptr == S1.length()) Aptr = 0;
		if (Bptr == S2.length()) Bptr = 0;
		if (S1[Aptr] > S2[Bptr]) return true;
		else if (S1[Aptr] < S2[Bptr]) return false;
		Aptr++;
		Bptr++;
	}
	return false;
}


string ItoS(long long A) {
	string result = "";
	while (A) {
		result = (char)('0' + A % 10) + result;
		A /= 10;
	}
	return result;
}
long long StoI(string S) {
	long long result = 0;
	long long temp = 1;
	for (int i = S.length() - 1; i >= 0; i--) {
		result += (S[i] - '0') * temp;
		temp *= 10;
	}
	return result;
}