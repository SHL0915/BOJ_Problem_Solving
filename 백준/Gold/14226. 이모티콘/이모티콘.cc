#include <iostream>
#include <queue>
using namespace std;

struct queueData {
	int screen, clipboard, time;
};

int S;
queue <queueData> q;
int mark[2000][2000] = { 0 };

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> S;
	q.push({ 1,0,0 });
	while (q.size())
		BFS();
	return 0;
}

void BFS() {
	int screen = q.front().screen;
	int clipboard = q.front().clipboard;
	int time = q.front().time;
	q.pop();
	if (screen == S) {
		cout << time;
		exit(0);
	}
	if (mark[screen][clipboard] != 0)
		return;
	mark[screen][clipboard] = 1;
	if (screen > 0)
		q.push({ screen - 1, clipboard,time + 1 });
	if (screen < 1000)
		q.push({ screen + clipboard, clipboard, time + 1 });
	if (screen < 1000)
		q.push({ screen, screen, time + 1 });
}