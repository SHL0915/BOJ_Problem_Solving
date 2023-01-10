#include <bits/stdc++.h>
using namespace std;

int T, N;
string p, input;

int strtoi(string s);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		deque <int> dq;
		int flag = 0, mode = 0;
		cin >> p >> N >> input;
		string temp = "";
		for (int i = 1; i < input.size(); i ++) {
			if (input[i] == ',' || input[i] == ']') {
				if(temp != "") dq.push_back(strtoi(temp));
				temp = "";
			}
			else temp += input[i];
		}
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') mode ^= 1;
			else {
				if (dq.size() == 0) {
					cout << "error\n";
					flag = 1;
					break;
				}
				if (mode) dq.pop_back();
				else dq.pop_front();
			}
		}
		if (flag) continue;
		else {
			if (dq.size() == 0) {
				cout << "[]\n";
			}
			else {
				cout << "[";
				if (mode) {
					for (int i = (int)dq.size() - 1; i >= 1; i--) cout << dq[i] << ',';
					cout << dq.front() << "]\n";
				}
				else {
					for (int i = 0; i < (int)dq.size() - 1; i++) cout << dq[i] << ',';
					cout << dq.back() << "]\n";
				}
			}
		}
	}
	return 0;
}

int strtoi(string s) {
	int ret = 0;
	for (int i = 0; i < s.length(); i++) {
		ret *= 10;
		ret += (s[i] - '0');
	}
	return ret;
}