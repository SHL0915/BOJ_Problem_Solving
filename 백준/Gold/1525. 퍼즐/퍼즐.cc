#include <iostream>
#include <queue>
#include <set>
using namespace std;

int puzzle[3][3];
int temp[3][3];
string ans = "123456780";
queue <pair<string, int>> q;
set <string> st;

void sToArr(string s);
string ArrToS();
void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> puzzle[i][j];
			temp[i][j] = puzzle[i][j];
		}
	}
	string input = ArrToS();
	q.push({ input, 0 });
	while (q.size()) BFS();
	cout << -1;
	return 0;
}

void sToArr(string s) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[i][j] = s[i * 3 + j] - '0';
		}
	}
	return;
}

string ArrToS() {
	string ret = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) ret += (temp[i][j] + '0');
	}
	return ret;
}

void BFS() {
	pair <string, int> data = q.front();
	q.pop();
	if (data.first == ans) {
		cout << data.second;
		exit(0);
	}
	if (st.find(data.first) != st.end()) return;
	st.insert(data.first);
	sToArr(data.first);
	int ref[3][3];
	int x, y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ref[i][j] = temp[i][j];
			if (temp[i][j] == 0) {
				x = j;
				y = i;
			}
		}
	}
	if (x > 0) {
		temp[y][x] = ref[y][x - 1];
		temp[y][x - 1] = ref[y][x];
		string input = ArrToS();
		q.push({ input,data.second + 1 });
		temp[y][x] = ref[y][x];
		temp[y][x - 1] = ref[y][x - 1];
	}
	if (y > 0) {
		temp[y][x] = ref[y - 1][x];
		temp[y - 1][x] = ref[y][x];
		string input = ArrToS();
		q.push({ input,data.second + 1 });
		temp[y][x] = ref[y][x];
		temp[y - 1][x] = ref[y - 1][x];
	}
	if (x < 2) {
		temp[y][x] = ref[y][x + 1];
		temp[y][x + 1] = ref[y][x];
		string input = ArrToS();
		q.push({ input,data.second + 1 });
		temp[y][x] = ref[y][x];
		temp[y][x + 1] = ref[y][x + 1];
	}
	if (y < 2) {
		temp[y][x] = ref[y + 1][x];
		temp[y + 1][x] = ref[y][x];
		string input = ArrToS();
		q.push({ input,data.second + 1 });
		temp[y][x] = ref[y][x];
		temp[y + 1][x] = ref[y + 1][x];
	}
	return;
}