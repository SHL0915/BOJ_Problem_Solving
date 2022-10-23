#include <iostream>
#include <vector>
#include <deque>
using namespace std;

char p[5];
string S;
deque <long long> num[5];
deque <char> op[5];

long long StoI(string str);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 4; i++) {
		int input;
		cin >> input;
		switch (i) {
		case 0: p[5 - input] = '+'; break;
		case 1: p[5 - input] = '-'; break;
		case 2: p[5 - input] = '*'; break;
		case 3: p[5 - input] = '/'; break;
		}
	}
	cin >> S;
	string temp = "";
	for (int i = 0; i < S.length(); i++) {
		if (S[i] >= '0' && S[i] <= '9') temp += S[i];
		else {
			num[0].push_front(StoI(temp));
			op[0].push_front(S[i]);
			temp = "";
		}
	}
	num[0].push_front(StoI(temp));
	for (int i = 1; ; i++) {
		if (num[i - 1].size() == 1) {
			cout << num[i - 1].back();
			return 0;
		}
		num[i].push_back(num[i - 1].front());
		num[i - 1].pop_front();
		while (num[i - 1].size()) {
			if (op[i - 1].front() != p[i]) {
				op[i].push_back(op[i - 1].front());
				num[i].push_back(num[i - 1].front());
				op[i - 1].pop_front();
				num[i - 1].pop_front();
			}
			else {
				long long result = num[i].back();
				switch (p[i]) {
				case '+': result += num[i - 1].front(); break;
				case '-': result -= num[i - 1].front(); break;
				case '*': result *= num[i - 1].front(); break;
				case '/': result /= num[i - 1].front(); break;
				}
				op[i - 1].pop_front();
				num[i - 1].pop_front();
				num[i].pop_back();
				num[i].push_back(result);
			}
		}
	}
	return 0;
}

long long StoI(string str) {
	long long result = 0;
	long long temp = 1;
	for (int i = str.length() - 1; i >= 0; i--) {
		result += (str[i] - '0') * temp;
		temp *= 10;
	}
	return result;
}