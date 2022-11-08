#include <iostream>
#include <queue>
using namespace std;

int T, A, B, flag;
queue <pair<pair<int, char>, pair<int, int>>> q;
int mark[10000][3];
string ans;

void BFS();

int D(int n) {
	return (n * 2) % 10000;
}

int S(int n) {
	if (n == 0) return 9999;
	else return n - 1;
}

int L(int n) {
	int d1 = n / 1000;
	return (n % 1000) * 10 + d1;
}

int R(int n) {
	int d4 = n % 10;
	return (n / 10) + d4 * 1000;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		flag = 0;
		ans = "";
		cin >> A >> B;
		for (int i = 0; i < 10000; i++) mark[i][0] = -1;
		q.push({ {A,'A'}, {A,0} });
		while (q.size()) BFS();
		int temp = B;
		while (1) {
			ans = (char)mark[temp][1] + ans;
			temp = mark[temp][2];
			if (temp == A) break;
		}
		cout << ans << '\n';
	}
	return 0;
}

void BFS() {
	pair<pair<int, char>, pair<int, int>> temp = q.front();
	q.pop();
	int now = temp.first.first;
	char path = temp.first.second;
	int d = temp.second.second;
	int before = temp.second.first;
	if (flag == 1) return;
	if (mark[now][0] != -1) return;
	mark[now][0] = d;
	mark[now][1] = path;
	mark[now][2] = before;
	if (now == B) {
		flag = 1;
		return;
	}
	q.push({ {D(now),'D'},{now, d + 1} });
	q.push({ {S(now),'S'},{now, d + 1} });
	q.push({ {L(now),'L'},{now, d + 1} });
	q.push({ {R(now),'R'},{now, d + 1} });
	return;
}