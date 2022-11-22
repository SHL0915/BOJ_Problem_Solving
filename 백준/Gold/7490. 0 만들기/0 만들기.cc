#include <bits/stdc++.h>
using namespace std;

int T, N;
string equation;

void BackTracking(int idx, string state);
bool calculate(string state);
int convert(string num);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		equation = "";
		for (int i = 1; i <= N; i++) equation += (i + '0');
		BackTracking(0, "");
		cout << '\n';
	}
	return 0;
}

void BackTracking(int idx, string state) {
	if (idx == N - 1) {
		string result = "";
		result += equation[0];
		for (int i = 0; i < state.length(); i++) {
			result += state[i];
			result += equation[i + 1];
		}
		if (calculate(result) == true) cout << result << '\n';
	}
	else {
		BackTracking(idx + 1, state + " ");
		BackTracking(idx + 1, state + "+");
		BackTracking(idx + 1, state + "-");
	}
}

bool calculate(string state) {
	int result = 0;
	int num;
	string curr_num = "";
	string curr_oper = "";
	for (int i = 0; i < state.length(); i++) {
		if (state[i] == ' ') continue;
		else if (state[i] == '+' || state[i] == '-') {
			num = convert(curr_num);
			if (curr_oper == "") result = num;
			else if (curr_oper == "+") result += num;
			else result -= num;
			curr_num = "";
			curr_oper = state[i];
		}
		else curr_num += state[i];
	}
	num = convert(curr_num);
	if (curr_oper == "+") result += num;
	else result -= num;
	if (result == 0) return true;
	else return false;
}

int convert(string num) {
	int result = 0;
	int degree = 1;
	for (int i = num.length() - 1; i >= 0; i--) {
		result += degree * (num[i] - '0');
		degree *= 10;
	}
	return result;
}