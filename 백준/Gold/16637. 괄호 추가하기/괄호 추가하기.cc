#include <bits/stdc++.h>
using namespace std;

int N, ans = -1234567890;
vector <int> num;
vector <char> oper;

void BackTracking(int k, int val);

int operation(int A, int B, char c) {
	if (c == '+') return A + B;
	else if (c == '-') return A - B;
	else return A * B;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}	
	BackTracking(0, num[0]);
	cout << ans;
	return 0;
}

void BackTracking(int k, int val) {
	if (k >= num.size() - 1) ans = max(ans, val);	
	else {		
		BackTracking(k + 1, operation(val, num[k + 1], oper[k]));
		if (k <= (int)num.size() - 3) BackTracking(k + 2, operation(val, operation(num[k + 1], num[k + 2], oper[k + 1]), oper[k]));
	}
}