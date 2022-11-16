#include <iostream>
using namespace std;

const int INF = 1234567890;

int N, cnt1, cnt2;
string A, B;

string push(string S, int idx);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> A >> B;
	string temp1 = A;
	string temp2 = A;
	temp1 = push(temp1, 0);
	cnt1++;
	for (int i = 1; i < N; i++) {
		if (temp1[i - 1] != B[i - 1]) {
			temp1 = push(temp1, i);
			cnt1++;
		}
		if (temp2[i - 1] != B[i - 1]) {
			temp2 = push(temp2, i);
			cnt2++;
		}
	}
	if (temp1[N - 1] != B[N - 1]) cnt1 = INF;
	if (temp2[N - 1] != B[N - 1]) cnt2 = INF;
	int ans = min(cnt1, cnt2);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}

string push(string S, int idx) {
	string ret = S;
	if (idx != 0) {
		if (S[idx - 1] == '0') ret[idx - 1] = '1';
		else ret[idx - 1] = '0';
	}
	if (S[idx] == '0') ret[idx] = '1';
	else ret[idx] = '0';
	if (idx != N - 1) {
		if (S[idx + 1] == '0') ret[idx + 1] = '1';
		else ret[idx + 1] = '0';
	}
	return ret;
}