#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;

string N;
int m = INF, M = -INF;

void BackTracking(string s, int cnt);
int cntOdd(string s);
int strtoi(string s);
string itostr(int k);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;	
	BackTracking(N, cntOdd(N));
	cout << m << " " << M;
	return 0;
}

void BackTracking(string s, int cnt) {
	if (s.length() == 1) {
		m = min(m, cnt);
		M = max(M, cnt);
	}
	else if (s.length() == 2) {
		int next = s[0] - '0' + s[1] - '0';
		string next_str = itostr(next);
		BackTracking(next_str, cnt + cntOdd(next_str));	
	}
	else {
		for (int i = 1; i < s.length(); i++) {
			for (int j = i + 1; j < s.length(); j++) {
				string a = "", b = "", c = "";
				for (int k = 0; k < i; k++) a += s[k];
				for (int k = i; k < j; k++) b += s[k];
				for (int k = j; k < s.length(); k++) c += s[k];
				int next = strtoi(a) + strtoi(b) + strtoi(c);
				string next_str = itostr(next);
				BackTracking(next_str, cnt + cntOdd(next_str));
			}
		}
	}
	return;
}

int cntOdd(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		if ((s[i] - '0') % 2) ret++;
	}
	return ret;
}

int strtoi(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret *= 10;
		ret += (s[i] - '0');
	}
	return ret;
}

string itostr(int k) {
	string ret = "";
	while (k) {
		ret = (char)(k % 10 + '0') + ret;
		k /= 10;
	}
	return ret;
}