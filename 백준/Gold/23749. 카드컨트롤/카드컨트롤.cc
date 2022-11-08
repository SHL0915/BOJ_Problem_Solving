#include <iostream>
#include <queue>
#include <set>
using namespace std;

int N;
queue <pair<string, int>> q;
set <string> s;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	string org = "";
	for (int i = 0; i < 2 * N; i++) {
		char c;
		cin >> c;
		org += c;
	}
	q.push({ org,0 });
	while (q.size()) BFS();
	return 0;
}

void BFS() {
	pair <string, int> temp = q.front();
	q.pop();
	string now = temp.first;
	int d = temp.second;
	if (s.count(now) != 0) return;
	s.insert(now);
	int score = 0;
	for (int i = 0; i < now.length(); i += 2) {
		if (now[i] == 'O' && now[i + 1] == 'X') score++;
		else if (now[i] == 'X' && now[i + 1] == 'O') score--;
	}
	if (score > 0) {
		cout << d;
		exit(0);
	}
	for (int i = 1; i < now.length(); i++) {
		string next = now;
		next.erase(next.begin() + i);
		next = now[i] + next;
		q.push({ next, d + 1 });
	}
	return;
}