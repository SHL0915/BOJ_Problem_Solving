#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int N;
char arr[20][20];
map <pair<char, char>, int> val;
map <string, int> table;
string s = "", e = "";

void putval();
int DP(string state);

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	putval();
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) arr[i][j] = s[j];
	}
	string s = "";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			s += '0';
			e += '1';
		}
	}
	cout << DP(s);
	return 0;
}

int DP(string state) {
	if (state == e) return 0;
	if (table.count(state)) return table[state];
	table[state] = -INF;
	int x, y, pos;
	for (int i = 0; i < state.size(); i++) {
		if (state[i] == '0') {
			x = i % N;
			y = i / N;
			pos = i;
			break;
		}
	}
	string next = state; next[pos] = '1';
	if (x < N - 1) {
		if (state[pos + 1] == '0') {
			next[pos + 1] = '1';
			table[state] = max(table[state], val[{min(arr[y][x], arr[y][x + 1]), max(arr[y][x], arr[y][x + 1])}] + DP(next));
			next[pos + 1] = '0';
		}
	}
	if (y < N - 1) {
		if (state[pos + N] == '0') {
			next[pos + N] = '1';
			table[state] = max(table[state], val[{min(arr[y][x], arr[y + 1][x]), max(arr[y][x], arr[y + 1][x])}] + DP(next));
			next[pos + N] = '0';
		}
	}
	table[state] = max(table[state], DP(next));
	return table[state];
}

void putval() {
	val[{'A', 'A'}] = 100;
	val[{'A', 'B'}] = 70;
	val[{'A', 'C'}] = 40;
	val[{'A', 'F'}] = 0;
	val[{'B', 'B'}] = 50;
	val[{'B', 'C'}] = 30;
	val[{'B', 'F'}] = 0;
	val[{'C', 'C'}] = 20;
	val[{'C', 'F'}] = 0;
	val[{'F', 'F'}] = 0;
	return;
}