#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<long long, long long>> pill;

int N;
long long ans;
map <pair<int,long long>, long long> mark;
queue <pill> q;

void BFS();

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	q.push({ 1, {1,0} });
	while (q.size()) BFS();
	cout << ans;
	return 0;
}

void BFS() {
	pill f = q.front();
	q.pop();
	int now = f.first;
	long long cnt = f.second.first;
	long long copied = f.second.second;
	if (now > N) return;
	if (mark[{now, cnt}] > copied) return;
	mark[{now, cnt}] = copied;
	ans = max(ans, cnt);
	if (copied == 0) q.push({ now + 1, {cnt + 1, copied} });
	else q.push({ now + 1, {cnt + copied, copied} });
	q.push({ now + 3, {2 * cnt, cnt} });
}